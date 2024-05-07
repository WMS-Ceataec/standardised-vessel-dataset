using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.InvalidData;

internal sealed class InvalidGeneralFaker : Faker<GeneralInformation>
{
    internal InvalidGeneralFaker()
    {
        RuleFor(e => e.ShipName, _ => string.Empty);
        RuleFor(e => e.Imo, _ => string.Empty);
        RuleFor(e => e.ShipReportingDate, f => f.Date.Future());
    }
}
