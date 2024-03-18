using Ceataec.StandardizedVesselDataset.Exporters.Models;
using Ceataec.StandardizedVesselDataset.Validators.Exceptions;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Exporters;

/// <summary>
/// Represents a generic interface for exporting Standardized Vessel Datasets (SVD).
/// </summary>
public interface ISvdExporter
{
    /// <summary>
    /// Export SVD for Output format (XML, JSON, CSV)
    /// </summary>
    /// <param name="svd">The Standardized Vessel Dataset to export. It should not be null.</param>
    /// <returns>Returns <see cref="StandardizedVesselDatasetContent"/>.</returns>
    /// <exception cref="ArgumentNullException">Thrown if the input <paramref name="svd"/> is null.</exception>
    /// <exception cref="ValidatorException">Thrown if the provided model is not valid.</exception>
    public Task<StandardizedVesselDatasetContent> ExportAsync(Svd svd);

}
