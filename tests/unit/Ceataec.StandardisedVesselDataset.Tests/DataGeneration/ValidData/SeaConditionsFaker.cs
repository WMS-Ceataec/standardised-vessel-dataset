using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class SeaConditionsFaker : Faker<SeaConditions>    
    {
        public SeaConditionsFaker()
        {
            RuleFor(sc => sc.Current, f => f.Random.Number());        }
    }
}