namespace Ceataec.StandardizedVesselDataset.Exporters.Models;

/// <summary>
/// Represents a SVD exported content output
/// </summary>
/// <param name="Content">The file content (byte[]).></param>
/// <param name="FileName">The exported file name.></param>
public record StandardizedVesselDatasetContent(byte[] Content, string FileName);