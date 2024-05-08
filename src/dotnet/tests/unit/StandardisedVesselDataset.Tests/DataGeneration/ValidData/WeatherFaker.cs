using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class WeatherFaker : Faker<WeatherInformation>
{
    public WeatherFaker()
    {
        RuleFor(w => w.AirTemperature, f => f.Random.Number());
        RuleFor(w => w.WindForce, f => f.Random.Number());
    }
}