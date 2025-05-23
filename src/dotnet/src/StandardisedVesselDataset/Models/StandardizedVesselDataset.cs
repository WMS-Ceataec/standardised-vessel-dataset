namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the Standardised Vessel Dataset (SVD)
/// See more: https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/
/// </summary>
public class StandardisedVesselDataset
{
    public GeneralInformation General { get; init; }
    public PortInformation PortAndRoute{ get; init; }
    public ArrivalTimes ArrivalTimes { get; init; }
    public DeviationFromPlanned DeviationFromPlanned { get; init; }
    public SpeedAndDistance SpeedAndDistance { get; init; }
    public WeatherInformation Weather { get; init; }
    public FreshWater FreshWater { get; init; }
    public ElectricityConsumption ElectricityConsumption { get; init; }
    public CargoInformation Cargo { get; init; }
    public FuelAndBunkerInformation FuelAndBunker { get; init; }
    public Emissions Emissions { get; init; }
    public CylinderLubeOilInformation CylinderLubeOil { get; init; }
}