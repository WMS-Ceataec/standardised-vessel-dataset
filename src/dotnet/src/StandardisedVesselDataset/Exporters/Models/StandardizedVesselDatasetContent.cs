namespace StandardisedVesselDataset.Exporters.Models;

/// <summary>
/// Represents a SVD exported content output
/// </summary>
/// <param name="Content">The file content (byte[]).></param>
/// <param name="FileName">The exported file name.></param>
public record StandardisedVesselDatasetContent(byte[] Content, string FileName);