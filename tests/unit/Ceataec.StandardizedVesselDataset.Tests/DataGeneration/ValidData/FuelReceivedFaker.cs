using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class FuelReceivedFaker : Faker<FuelReceived>
    {
        public FuelReceivedFaker()
        {
            RuleFor(fr => fr.BunkerEthanol, f => f.Random.Number());
        }
    }
}