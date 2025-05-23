using Bogus;
using StandardisedVesselDataset.Models;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class SvdFaker : Faker<Svd>
{
    internal SvdFaker()
    {
        RuleFor(e => e.General, _ => new GeneralFaker().Generate());
        RuleFor(e => e.PortAndRoute, _ => new PortInformationFaker().Generate());
        RuleFor(e => e.ArrivalTimes, _ => new ArrivalTimesFaker().Generate());
        RuleFor(e => e.DeviationFromPlanned, _ => new DeviationFromPlannedFaker().Generate());
        RuleFor(e => e.SpeedAndDistance, _ => new SpeedAndDistanceFaker().Generate());
        RuleFor(e => e.Weather, _ => new WeatherFaker().Generate());
        RuleFor(e => e.FreshWater, _ => new FreshWaterFaker().Generate());
        RuleFor(e => e.ElectricityConsumption, _ => new ElectricityConsumptionFaker().Generate());
        RuleFor(e => e.Cargo, _ => new CargoInformationFaker().Generate());
        RuleFor(e => e.FuelAndBunker, _ => new FuelAndBunkerFaker().Generate());
        RuleFor(e => e.Emissions, _ => new EmissionsFaker().Generate());
        RuleFor(e => e.CylinderLubeOil, _ => new CylinderLubeOilFaker().Generate());
    }

}
