using FluentValidation;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Validators;

public class StandardisedVesselDatasetValidator : AbstractValidator<Models.StandardisedVesselDataset>
{
    public StandardisedVesselDatasetValidator()
    {
        RuleFor(nr => nr.General).SetValidator(new GeneralValidator());

        //extend validation rules
    }
}
