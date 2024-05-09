using FluentValidation;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Validators;

public class GeneralValidator : AbstractValidator<GeneralInformation>
{
    public GeneralValidator()
    {
        RuleFor(g => g.Imo).NotEmpty().WithMessage("{PropertyName} is required");
        RuleFor(g => g.Imo).Length(7).WithMessage("{PropertyName} must be seven digits.");
        RuleFor(g => g.ShipName).NotEmpty().WithMessage("{PropertyName} is required");
        RuleFor(g => g.ShipReportingDate).GreaterThan(DateTime.MinValue).WithMessage("{PropertyName} (Datetime) must be greater than default.");
    }
}