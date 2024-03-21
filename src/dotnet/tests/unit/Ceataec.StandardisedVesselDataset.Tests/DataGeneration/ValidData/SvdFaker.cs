using Bogus;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class SvdFaker : Faker<Svd>
{
    internal SvdFaker()
    {
        RuleFor(e => e.General, _ => new GeneralFaker().Generate());
        RuleFor(e => e.PortAndRouteInformation, _ => new PortAndRouteInformationFaker().Generate());
        RuleFor(e => e.SpeedAndDistance, _ => new SpeedAndDistanceFaker().Generate());
        RuleFor(e => e.Weather, _ => new WeatherFaker().Generate());
        RuleFor(e => e.SeaConditions, _ => new SeaConditionsFaker().Generate());
        RuleFor(e => e.FuelRemaining, _ => new FuelRemainingFaker().Generate());
        RuleFor(e => e.FuelConsumption, _ => new FuelConsumptionFaker().Generate());
        RuleFor(e => e.Water, _ => new WaterFaker().Generate());
        RuleFor(e => e.EmissionsReporting, _ => new EmissionsReportingFaker().Generate());
        RuleFor(e => e.FuelReceived, _ => new FuelReceivedFaker().Generate());
    }

}
