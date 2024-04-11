using StandardisedVesselDataset.Exporters.Models;
using StandardisedVesselDataset.Validators.Exceptions;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Exporters;

/// <summary>
/// Represents a generic interface for exporting Standardised Vessel Datasets (SVD).
/// </summary>
public interface ISvdExporter
{
    /// <summary>
    /// Export SVD for Output format (XML, JSON, CSV)
    /// </summary>
    /// <param name="svd">The Standardised Vessel Dataset to export. It should not be null.</param>
    /// <returns>Returns <see cref="StandardisedVesselDatasetContent"/>.</returns>
    /// <exception cref="ArgumentNullException">Thrown if the input <paramref name="svd"/> is null.</exception>
    /// <exception cref="ValidatorException">Thrown if the provided model is not valid.</exception>
    public Task<StandardisedVesselDatasetContent> ExportAsync(Svd svd);

}
