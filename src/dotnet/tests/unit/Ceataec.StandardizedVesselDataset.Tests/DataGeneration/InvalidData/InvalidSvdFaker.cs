using Bogus;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.InvalidData
{
    internal sealed class InvalidSvdFaker : Faker<Svd>
    {
        internal InvalidSvdFaker()
        {
            RuleFor(e => e.General, _ => new InvalidGeneralFaker().Generate());
        }

    }
}
