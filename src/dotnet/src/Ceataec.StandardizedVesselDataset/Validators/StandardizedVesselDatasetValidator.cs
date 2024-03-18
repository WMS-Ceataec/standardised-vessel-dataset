using FluentValidation;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Validators;

public class StandardizedVesselDatasetValidator : AbstractValidator<Svd>
{
    public StandardizedVesselDatasetValidator()
    {
        RuleFor(nr => nr.General).SetValidator(new GeneralValidator());

        //extend validation rules
    }
}
