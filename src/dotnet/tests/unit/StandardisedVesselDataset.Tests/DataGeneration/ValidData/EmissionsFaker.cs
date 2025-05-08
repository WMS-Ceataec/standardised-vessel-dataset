using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

public class EmissionsFaker : Faker<Emissions>
{
    internal EmissionsFaker()
    {
        RuleFor(a => a.TotalCh4, f => f.Random.Double());
        RuleFor(a => a.TotalCo2, f => f.Random.Double());
    }
}