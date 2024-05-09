using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class FreshWaterFaker : Faker<FreshWater>
{
    public FreshWaterFaker()
    {
        RuleFor(w => w.FreshWaterConsumed, f => f.Random.Number());
        RuleFor(w => w.FreshWaterBunkered, f => f.Random.Number());
    }
}