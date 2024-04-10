using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class WeatherFaker : Faker<Weather>
    {
        public WeatherFaker()
        {
            RuleFor(w => w.AirTemp, f => f.Random.Number());
            RuleFor(w => w.WindForce, f => f.Random.Number());
        }
    }
}