using Bogus;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

public class ElectricityConsumptionFaker : Faker<Models.ElectricityConsumption>
{
    internal ElectricityConsumptionFaker()
    {
        RuleFor(e => e.OffsetElectricityConsumption, e => e.Random.Number());
        RuleFor(e => e.PowerConsumptionForPlant, e => e.Random.Number());
    }
}