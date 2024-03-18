using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelConsumptionFaker : Faker<FuelConsumption>
    {
        public FuelConsumptionFaker()
        {
            RuleFor(fc => fc.EthanolConsumedTotal, f => f.Random.Number());
        }
    }
}