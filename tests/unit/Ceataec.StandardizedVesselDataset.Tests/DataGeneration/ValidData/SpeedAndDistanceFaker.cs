using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
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