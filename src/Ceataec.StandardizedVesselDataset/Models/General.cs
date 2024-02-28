namespace Ceataec.StandardizedVesselDataset.Models;

/// <summary>
/// Represent the General section of SVD
/// </summary>
public class General
{
    public string Position { get; init; }
    public DateTime Time { get; init; }
    public string VesselName { get; init; }
    public string Imo { get; init; }
    public string ShipType { get; init; }
    public string VoyageNumber { get; init; }
    public string Leg { get; init; }
    public string Remarks { get; init; }
}