using Ceataec.StandardizedVesselDataset.Exporters.Models;
using Ceataec.StandardizedVesselDataset.Validators.Errors;
using Ceataec.StandardizedVesselDataset.Validators.Exceptions;
using FluentValidation;

namespace Ceataec.StandardizedVesselDataset.Exporters.Formats;

internal abstract class BaseExporter(IValidator<StandardizedVesselDataset.Models.StandardizedVesselDataset> validator) : ISvdExporter
{
    public async Task<StandardizedVesselDatasetContent> ExportAsync(StandardizedVesselDataset.Models.StandardizedVesselDataset svd)
    {
        ArgumentNullException.ThrowIfNull(svd);

        var validationResult = await validator.ValidateAsync(svd);
        if (!validationResult.IsValid)
        {
            throw new ValidatorException(validationResult.Errors
                .Select(e => new ValidationError(e.PropertyName, e.ErrorMessage)));
        }

        return await InternalExportAsync(svd);
    }

    protected abstract Task<StandardizedVesselDatasetContent> InternalExportAsync(StandardizedVesselDataset.Models.StandardizedVesselDataset svd);
}
