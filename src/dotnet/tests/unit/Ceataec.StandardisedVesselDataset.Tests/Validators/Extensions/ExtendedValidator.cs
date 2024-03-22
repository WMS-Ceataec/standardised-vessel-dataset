using Ceataec.StandardisedVesselDataset.Validators;
using FluentValidation;

namespace Ceataec.StandardisedVesselDataset.Tests.Validators.Extensions;

public class ExtendedValidator : StandardisedVesselDatasetValidator
{
    public ExtendedValidator() : base()
    {
        RuleFor(f => f.SpeedAndDistance).NotNull().WithMessage("Speed and distance is required");
    }
}
