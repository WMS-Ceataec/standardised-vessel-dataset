namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Speed and Distance section of SVD
/// </summary>
public class SpeedAndDistance
{
    public double BoilerElectricityConsumption { get; init; }
    public double GeneratorProduction { get; init; }
    public double Draft { get; init; }
    public double DraftFore { get; init; }
    public double DraftAft { get; init; }
    public double Dwt { get; init; }
    public double Heading { get; init; }
    public double CpOrderSpeed { get; init; }
    public double ObservedDistanceNm { get; init; }
    public double ObservedDistanceKm { get; init; }
    public double Rpm { get; init; }
    public double SlipPercentage { get; init; }
    public double EngineDistanceNm { get; init; }
    public double EngineDistanceKm { get; init; }
    public double SpeedOverGroundKn { get; init; }
    public double SpeedOverGroundKmh { get; init; }
    public double SpeedOverWaterKn { get; init; }
    public double SpeedOverWaterKmh { get; init; }
    public double DistanceRunByLog { get; init; }
    public double DistanceRunByOg { get; init; }
}