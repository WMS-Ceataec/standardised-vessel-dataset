using Bogus;
using Ceataec.StandardizedVesselDataset.Models;

namespace Ceataec.StandardizedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class PortAndRouteInformationFaker : Faker<PortAndRouteInformation>
    {
        public PortAndRouteInformationFaker()
        {
            RuleFor(e => e.DepartureTime, f => f.Date.Future());
            RuleFor(e => e.DeparturePort, f => f.Address.City());
            RuleFor(e => e.DestinationPort, f => f.Address.City());
        }
    }
}