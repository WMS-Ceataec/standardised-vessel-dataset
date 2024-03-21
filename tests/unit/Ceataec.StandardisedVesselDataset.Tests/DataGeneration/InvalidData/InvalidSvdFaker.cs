using Bogus;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.InvalidData
{
    internal sealed class InvalidSvdFaker : Faker<Svd>
    {
        internal InvalidSvdFaker()
        {
            RuleFor(e => e.General, _ => new InvalidGeneralFaker().Generate());
        }

    }
}
