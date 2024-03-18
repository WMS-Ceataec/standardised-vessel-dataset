using Ceataec.StandardizedVesselDataset.Tests.DataGeneration.InvalidData;
using Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData;
using Ceataec.StandardizedVesselDataset.Validators;
using FluentAssertions;
using FluentValidation;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Tests.Validators;

public class SvdValidatorTests
{
    private readonly IValidator<Svd> _validator = new StandardizedVesselDatasetValidator();

    [Fact]
    public async Task ValidateAsync_GivenValidData_ShouldValidateSuccessfully()
    {
        var svd = new SvdFaker().Generate();

        var validationResult = await _validator.ValidateAsync(svd);

        validationResult.Should().NotBeNull();
        validationResult.IsValid.Should().BeTrue(); 
    }

    [Fact]
    public async Task ValidateAsync_GivenInvalidData_ShouldValidateWithErrors()
    {
        var svd = new InvalidSvdFaker().Generate();

        var validationResult = await _validator.ValidateAsync(svd);

        validationResult.Should().NotBeNull();
        validationResult.IsValid.Should().BeFalse();
        validationResult.Errors.Should().NotBeNull();   
        validationResult.Errors.Count.Should().NotBe(0);
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "IMO is required");
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "IMO must be seven digits.");
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "VesselName is required");
    }
}
