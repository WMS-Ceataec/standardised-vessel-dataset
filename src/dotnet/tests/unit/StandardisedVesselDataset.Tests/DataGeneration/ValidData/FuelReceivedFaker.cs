using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelReceivedFaker : Faker<FuelReceived>
    {
        public FuelReceivedFaker()
        {
            RuleFor(fr => fr.BunkerEthanol, f => f.Random.Number());
        }
    }
}