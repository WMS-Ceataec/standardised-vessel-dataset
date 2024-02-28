using Ceataec.StandardizedVesselDataset.Models;
using FluentValidation;

namespace Ceataec.StandardizedVesselDataset.Validators;

public class GeneralValidator : AbstractValidator<General>
{
    public GeneralValidator()
    {
        RuleFor(g => g.Imo).NotEmpty().WithMessage("IMO is required");
        RuleFor(g => g.Imo).Length(7).WithMessage("IMO must be seven digits.");
        RuleFor(g => g.VesselName).NotEmpty().WithMessage("VesselName is required");
        RuleFor(g => g.Time).GreaterThan(DateTime.MinValue).WithMessage("Time (Datetime) must be greater than default.");
    }
}