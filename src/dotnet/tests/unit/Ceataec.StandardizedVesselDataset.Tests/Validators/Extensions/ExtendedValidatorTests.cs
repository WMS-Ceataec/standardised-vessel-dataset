using Ceataec.StandardizedVesselDataset.Tests.DataGeneration.InvalidData;
using Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData;
using FluentAssertions;
using FluentValidation;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Tests.Validators.Extensions;

public class ExtendedValidatorTests
{
    private readonly IValidator<Svd> _validator = new ExtendedValidator();

    [Fact]
    public async Task ValidateAsync_GivenValidData_ShouldValidateSuccessfully()
    {
        var svd = new SvdFaker().Generate();

        var validationResult = await _validator.ValidateAsync(svd);

        validationResult.Should().NotBeNull();
        validationResult.IsValid.Should().BeTrue();
        validationResult.Errors.Should().BeNullOrEmpty();
    }

    [Fact]
    public async Task ValidateAsync_GivenInvalidData_ShouldFailOnValidation()
    {
        var svd = new InvalidSvdFaker().Generate();

        var validationResult = await _validator.ValidateAsync(svd);

        validationResult.Should().NotBeNull();
        validationResult.IsValid.Should().BeFalse();
        validationResult.Errors.Should().NotBeNull();
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "Speed and distance is required");
    }
}
