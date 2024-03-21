using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class SpeedAndDistanceFaker : Faker<SpeedAndDistance>
    {
        public SpeedAndDistanceFaker()
        {
            RuleFor(sd => sd.EngineDistanceKm, f => f.Random.Number());
            RuleFor(sd => sd.SpeedOverGroundKmh, f => f.Random.Number());
        }
    }
}