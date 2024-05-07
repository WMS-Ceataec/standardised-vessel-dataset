using StandardisedVesselDataset.Tests.DataGeneration.InvalidData;
using StandardisedVesselDataset.Tests.DataGeneration.ValidData;
using StandardisedVesselDataset.Validators;
using FluentAssertions;
using FluentValidation;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Tests.Validators;

public class SvdValidatorTests
{
    private readonly IValidator<Svd> _validator = new StandardisedVesselDatasetValidator();

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
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "Imo is required");
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "Imo must be seven digits.");
        validationResult.Errors.Should().Contain(e => e.ErrorMessage == "Ship Name is required");
    }
}
