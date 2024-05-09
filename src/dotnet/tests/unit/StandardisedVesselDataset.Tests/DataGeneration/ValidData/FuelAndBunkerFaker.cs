using Bogus;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

public class FuelAndBunkerFaker : Faker<Models.FuelAndBunkerInformation>
{
    internal FuelAndBunkerFaker()
    {
        RuleFor(f => f.FuelType, f => f.Commerce.ProductName());
        RuleFor(f => f.FuelRemainingOnBoard, f => f.Random.Number());
    }
}