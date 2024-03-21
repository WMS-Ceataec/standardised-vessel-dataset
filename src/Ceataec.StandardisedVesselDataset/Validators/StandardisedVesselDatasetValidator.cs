using FluentValidation;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Validators;

public class StandardisedVesselDatasetValidator : AbstractValidator<Svd>
{
    public StandardisedVesselDatasetValidator()
    {
        RuleFor(nr => nr.General).SetValidator(new GeneralValidator());

        //extend validation rules
    }
}
