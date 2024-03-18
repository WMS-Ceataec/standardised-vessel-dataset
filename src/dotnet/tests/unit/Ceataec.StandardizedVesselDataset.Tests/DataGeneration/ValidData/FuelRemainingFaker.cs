using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelRemainingFaker : Faker<FuelRemaining>
    {
        public FuelRemainingFaker()
        {
            RuleFor(fr => fr.MethanolRob, f => f.Random.Number());
        }
    }
}