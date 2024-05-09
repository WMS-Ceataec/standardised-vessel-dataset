using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class GeneralFaker : Faker<GeneralInformation>
{
    internal GeneralFaker()
    {
        RuleFor(e => e.ShipName, f => f.Company.CompanyName());
        RuleFor(e => e.Imo, f => f.Random.Number(9000000, 9999999).ToString());
        RuleFor(e => e.ShipReportingDate, f => f.Date.Future());
    }
}
