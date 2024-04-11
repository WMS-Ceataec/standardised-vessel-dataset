namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Fuel Remaining section of SVD
/// </summary>
public class FuelRemaining
{
    public double BunkerRob { get; init; }
    public double Hforob { get; init; }
    public double Lsgorob { get; init; }
    public double Lsforob { get; init; }
    public double Mdorob { get; init; }
    public double LpgButaneRob { get; init; }
    public double LpgPropaneRob { get; init; }
    public double LngMethaneRob { get; init; }
    public double EthanolRob { get; init; }
    public double MethanolRob { get; init; }
    public double CylinderLubeOilRob { get; init; } 
    public double LoConsumption { get; init; }
}