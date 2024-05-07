namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Deviation from Planned section of SVD
/// </summary>
public class DeviationFromPlanned
{
    /// <summary>
    /// Description of why the ship has deviated from the planned voyage.
    /// </summary>
    public string Reason { get; init; }

    /// <summary>
    /// Latitude (geographical coordinate) of the location of the ship at the time of deviation.
    /// </summary>
    public double Latitude { get; init; }

    /// <summary>
    /// Longitude (geographical coordinate) of the location of the ship at the time of deviation.
    /// </summary>
    public double Longitude { get; init; }

    /// <summary>
    /// Date and time when the ship started its deviation from the planned voyage.
    /// </summary>
    public DateTime ShipDeviationStartedTime { get; init; }

    /// <summary>
    /// Date and time when the ship stopped its deviation from the planned voyage.
    /// </summary>
    public DateTime ShipDeviationStoppedTime { get; init; }
}
