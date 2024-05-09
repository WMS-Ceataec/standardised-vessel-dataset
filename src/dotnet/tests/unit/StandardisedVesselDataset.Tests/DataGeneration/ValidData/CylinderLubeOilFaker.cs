using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

public class CylinderLubeOilFaker : Faker<CylinderLubeOilInformation>
{
    internal CylinderLubeOilFaker()
    {
        RuleFor(c => c.Consumption, f => f.Random.Number());
        RuleFor(c => c.RemainingOnBoard, f => f.Random.Number());
    }
}