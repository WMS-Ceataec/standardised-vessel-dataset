using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData
{
    internal sealed class PortInformationFaker : Faker<PortInformation>
    {
        public PortInformationFaker()
        {
            RuleFor(e => e.DeparturePortCode, f => f.Address.CityPrefix());
            RuleFor(e => e.ArrivalPortCode, f => f.Address.CityPrefix());
            RuleFor(e => e.DeparturePortDescription, f => f.Address.City());
            RuleFor(e => e.ArrivalPortDescription, f => f.Address.City());
        }
    }
}