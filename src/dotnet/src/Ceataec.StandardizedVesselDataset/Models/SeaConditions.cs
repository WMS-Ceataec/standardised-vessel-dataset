namespace Ceataec.StandardizedVesselDataset.Models;

/// <summary>
/// Represent the Sea Conditions section of SVD
/// </summary>
public class SeaConditions
{
    public double SeaDirectionMagnetic { get; init; }
    public double SeaDirectionTrue { get; init; }
    public double SwellDirectionMagnetic { get; init; }
    public double SwellDirectionTrue { get; init; }
    public double WindDirectionMagnetic { get; init; }
    public double WindDirectionTrue { get; init; }
    public double BadWeatherHours { get; init; }
    public double BadWeatherDistance { get; init; }
    public double SeaHeight { get; init; }
    public double SwellHeight { get; init; }
    public double Current { get; init; }
}