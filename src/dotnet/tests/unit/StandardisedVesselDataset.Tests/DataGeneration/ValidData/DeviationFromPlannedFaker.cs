using Bogus;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal class DeviationFromPlannedFaker : Faker<Models.DeviationFromPlanned>
{
    public DeviationFromPlannedFaker()
    {
        RuleFor(d => d.ShipDeviationStartedTime, f => f.Date.Past());
        RuleFor(d => d.ShipDeviationStoppedTime, f => f.Date.Past());
    }
}