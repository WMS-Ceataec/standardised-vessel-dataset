using Ceataec.StandardisedVesselDataset.Exporters;
using Ceataec.StandardisedVesselDataset.Tests.DataGeneration.InvalidData;
using Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData;
using Ceataec.StandardisedVesselDataset.Validators;
using Ceataec.StandardisedVesselDataset.Validators.Exceptions;
using FluentAssertions;
using FluentValidation;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Tests.Exporters;

public abstract class BaseExporterTests
{
    protected IValidator<Svd> Validator { get; } = new StandardisedVesselDatasetValidator();
    protected abstract ISvdExporter Exporter { get; }

    [Fact]
    public async Task ExportAsync_GivenNullArgument_ShouldThrowArgumentNullException()
    {
        var reportFunc = () => Exporter.ExportAsync(null);

        (await reportFunc.Should().ThrowAsync<ArgumentNullException>()).WithParameterName("svd");
    }

    [Fact]
    public async Task ExportAsync_GivenInvalidData_ShouldThrowValidatorException()
    {
        var invalidData = new InvalidSvdFaker().Generate();

        var reportFunc = () => Exporter.ExportAsync(invalidData);

        await reportFunc.Should().ThrowAsync<ValidatorException>().WithMessage("Validation failed: \n -- General.IMO: IMO is required;*");
    }

    [Fact]
    public async Task ExportAsync_GivenValidSvd_ShouldExportSuccessfully()
    {
        var svd = new SvdFaker().Generate();

        var report = await Exporter.ExportAsync(svd);

        report.Should().NotBeNull();
        report.FileName.Should().NotBeNullOrEmpty();
        report.FileName.Should().Contain($"{svd.General.Imo}");
        report.Content.Should().NotBeNull();
        var svdData = DeserializeContent(report.Content);
        svd.Should().BeEquivalentTo(svdData);
    }

    protected abstract Svd DeserializeContent(byte[] svd);
}
