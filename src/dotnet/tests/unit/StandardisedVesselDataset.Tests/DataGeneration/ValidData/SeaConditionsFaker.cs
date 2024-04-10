using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class SeaConditionsFaker : Faker<SeaConditions>    
    {
        public SeaConditionsFaker()
        {
            RuleFor(sc => sc.Current, f => f.Random.Number());        }
    }
}