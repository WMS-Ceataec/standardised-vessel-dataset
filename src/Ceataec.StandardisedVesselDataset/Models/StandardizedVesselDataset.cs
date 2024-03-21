namespace Ceataec.StandardisedVesselDataset.Models;

/// <summary>
/// Represents the Standardised Vessel Dataset (SVD)
/// See more: https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/
/// </summary>
public class StandardisedVesselDataset
{
    public General General { get; init; }
    public PortAndRouteInformation PortAndRouteInformation { get; init; }
    public SpeedAndDistance SpeedAndDistance { get; init; }
    public Weather Weather { get; init; }
    public SeaConditions SeaConditions { get; init; }
    public FuelRemaining FuelRemaining { get; init; }
    public Water Water { get; init; }
    public FuelConsumption FuelConsumption { get; init; }
    public FuelReceived FuelReceived { get; init; }
    public EmissionsReporting EmissionsReporting { get; init; }
}