using Ceataec.StandardisedVesselDataset.Exporters.Formats.CSV;
using Ceataec.StandardisedVesselDataset.Exporters.Formats.Json;
using Ceataec.StandardisedVesselDataset.Exporters.Formats.XML;
using Ceataec.StandardisedVesselDataset.Extensions;
using Ceataec.StandardisedVesselDataset.Models;
using Ceataec.StandardisedVesselDataset.Validators;
using FluentAssertions;
using FluentValidation;
using Microsoft.Extensions.DependencyInjection;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Tests.ServiceCollectionExtensions;

public class ServicesCollectionExtensionsTests
{
    [Fact]
    public void AddSvd_ShouldRegisterValidatorsAndExporters()
    {
        var services = new ServiceCollection();

        services.AddSvd();

        services.Should().ContainSingle(x => x.ServiceType == typeof(IValidator<Svd>) && x.ImplementationType == typeof(StandardisedVesselDatasetValidator));
        services.Should().Contain(x => x.ServiceType == typeof(IValidator<General>) && x.ImplementationType == typeof(GeneralValidator));
        services.Should().Contain(x => x.ServiceType == typeof(ISvdXmlExporter) && x.ImplementationType != null && typeof(ISvdXmlExporter).IsAssignableFrom(x.ImplementationType));
        services.Should().Contain(x => x.ServiceType == typeof(ISvdCsvExporter) && x.ImplementationType != null && typeof(ISvdCsvExporter).IsAssignableFrom(x.ImplementationType));
        services.Should().Contain(x => x.ServiceType == typeof(ISvdJsonExporter) && x.ImplementationType != null && typeof(ISvdJsonExporter).IsAssignableFrom(x.ImplementationType));
    }
}
