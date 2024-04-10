using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class WaterFaker : Faker<Water>
    {
        public WaterFaker()
        {
            RuleFor(w => w.FreshWaterConsumed, f => f.Random.Number());
            RuleFor(w => w.FreshWaterRob, f => f.Random.Number());
        }
    }
}