using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelRemainingFaker : Faker<FuelRemaining>
    {
        public FuelRemainingFaker()
        {
            RuleFor(fr => fr.MethanolRob, f => f.Random.Number());
        }
    }
}