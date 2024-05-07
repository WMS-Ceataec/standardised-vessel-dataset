using Bogus;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

public class CargoInformationFaker : Faker<Models.CargoInformation>
{
    internal CargoInformationFaker()
    {
        RuleFor(c => c.GrossVolume, f => f.Random.Number());
        RuleFor(c => c.CargoDescription, f => f.Lorem.Paragraph());
    }
}