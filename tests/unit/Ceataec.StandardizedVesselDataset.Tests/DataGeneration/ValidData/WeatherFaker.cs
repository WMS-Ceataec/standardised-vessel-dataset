using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
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