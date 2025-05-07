using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

public class ArrivalTimesFaker : Faker<ArrivalTimes>
{
    internal ArrivalTimesFaker()
    {
        RuleFor(a => a.Arrival, f => f.Date.Future());
        RuleFor(a => a.Departure, f => f.Date.Soon());
    }
}