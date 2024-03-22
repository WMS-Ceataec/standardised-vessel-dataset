using Bogus;
using Ceataec.StandardisedVesselDataset.Models;

namespace Ceataec.StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class GeneralFaker : Faker<General>
{
    internal GeneralFaker()
    {
        RuleFor(e => e.VesselName, f => f.Company.CompanyName());
        RuleFor(e => e.Imo, f => f.Random.Number(9000000, 9999999).ToString());
        RuleFor(e => e.Time, f => f.Date.Future());
    }
}
