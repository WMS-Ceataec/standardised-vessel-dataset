using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class SpeedAndDistanceFaker : Faker<SpeedAndDistance>
{
    public SpeedAndDistanceFaker()
    {
        RuleFor(sd => sd.DistanceOverGround, f => f.Random.Number());
        RuleFor(sd => sd.DistanceToNextPort, f => f.Random.Number());
        RuleFor(sd => sd.SpeedOverGround, f => f.Random.Number());
    }
}