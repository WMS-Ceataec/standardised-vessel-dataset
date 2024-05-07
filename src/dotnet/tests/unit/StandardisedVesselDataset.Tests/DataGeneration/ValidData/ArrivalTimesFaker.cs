using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    public class ArrivalTimesFaker : Faker<ArrivalTimes>
    {
        internal ArrivalTimesFaker()
        {
            RuleFor(a => a.Actual, f => f.Date.Soon());
            RuleFor(a => a.Eta, f => f.Date.Future());
        }
    }
}