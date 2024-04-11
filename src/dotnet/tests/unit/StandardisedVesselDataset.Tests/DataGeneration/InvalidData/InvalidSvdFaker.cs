using Bogus;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Tests.DataGeneration.InvalidData
{
    internal sealed class InvalidSvdFaker : Faker<Svd>
    {
        internal InvalidSvdFaker()
        {
            RuleFor(e => e.General, _ => new InvalidGeneralFaker().Generate());
        }

    }
}
