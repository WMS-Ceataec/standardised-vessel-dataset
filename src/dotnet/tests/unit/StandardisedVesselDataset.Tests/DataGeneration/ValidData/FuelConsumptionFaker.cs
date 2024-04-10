using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelConsumptionFaker : Faker<FuelConsumption>
    {
        public FuelConsumptionFaker()
        {
            RuleFor(fc => fc.EthanolConsumedTotal, f => f.Random.Number());
        }
    }
}