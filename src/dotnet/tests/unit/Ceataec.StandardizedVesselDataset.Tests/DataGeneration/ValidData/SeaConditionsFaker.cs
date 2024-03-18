using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class SeaConditionsFaker : Faker<SeaConditions>    
    {
        public SeaConditionsFaker()
        {
            RuleFor(sc => sc.Current, f => f.Random.Number());        }
    }
}