namespace Ceataec.StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Fuel Received section of SVD
/// </summary>
public class FuelReceived
{
    public double BunkerHfo { get; init; }
    public double BunkerLsfo { get; init; }
    public double BunkerMdo { get; init; }
    public double BunkerLsgo { get; init; }
    public double BunkerLpgButane { get; init; }
    public double BunkerLpgPropane { get; init; }
    public double BunkerLngMethane { get; init; }
    public double BunkerEthanol { get; init; }
    public double BunkerMethanol { get; init; }
}