using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelConsumptionFaker : Faker<FuelConsumption>
    {
        public FuelConsumptionFaker()
        {
            RuleFor(fc => fc.EthanolConsumedTotal, f => f.Random.Number());
        }
    }
}