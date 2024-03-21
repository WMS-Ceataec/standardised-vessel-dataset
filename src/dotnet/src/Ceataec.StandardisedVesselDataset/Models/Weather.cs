namespace Ceataec.StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Weather section of SVD
/// </summary>
public class Weather
{
    public double AirTemp { get; init; }
    public double BarPressure { get; init; }
    public string SeaState { get; init; }
    public string Swell { get; init; }
    public double WindForce { get; init; }
    public string CurrentDirection { get; init; }
}