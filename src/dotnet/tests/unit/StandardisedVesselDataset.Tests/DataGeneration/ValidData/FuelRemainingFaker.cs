using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelRemainingFaker : Faker<FuelRemaining>
    {
        public FuelRemainingFaker()
        {
            RuleFor(fr => fr.MethanolRob, f => f.Random.Number());
        }
    }
}