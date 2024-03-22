using Ceataec.StandardisedVesselDataset.Exporters.Models;
using Ceataec.StandardisedVesselDataset.Validators.Errors;
using Ceataec.StandardisedVesselDataset.Validators.Exceptions;
using FluentValidation;

namespace Ceataec.StandardisedVesselDataset.Exporters.Formats;

internal abstract class BaseExporter(IValidator<StandardisedVesselDataset.Models.StandardisedVesselDataset> validator) : ISvdExporter
{
    public async Task<StandardisedVesselDatasetContent> ExportAsync(StandardisedVesselDataset.Models.StandardisedVesselDataset svd)
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

    protected abstract Task<StandardisedVesselDatasetContent> InternalExportAsync(StandardisedVesselDataset.Models.StandardisedVesselDataset svd);
}
