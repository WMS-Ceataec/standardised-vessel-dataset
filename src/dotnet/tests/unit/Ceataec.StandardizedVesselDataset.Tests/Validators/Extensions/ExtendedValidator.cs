using Ceataec.StandardizedVesselDataset.Validators;
using FluentValidation;

namespace Ceataec.StandardizedVesselDataset.Tests.Validators.Extensions;

public class ExtendedValidator : StandardizedVesselDatasetValidator
{
    public ExtendedValidator() : base()
    {
        RuleFor(f => f.SpeedAndDistance).NotNull().WithMessage("Speed and distance is required");
    }
}
