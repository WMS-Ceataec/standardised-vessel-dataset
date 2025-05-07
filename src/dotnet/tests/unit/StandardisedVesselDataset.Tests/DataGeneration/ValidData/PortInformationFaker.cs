using Bogus;
using StandardisedVesselDataset.Models;

namespace StandardisedVesselDataset.Tests.DataGeneration.ValidData;

internal sealed class PortInformationFaker : Faker<PortInformation>
{
    public PortInformationFaker()
    {
        RuleFor(e => e.DeparturePortCode, f => f.Address.CityPrefix());
        RuleFor(e => e.ArrivalPortCode, f => f.Address.CityPrefix());
        RuleFor(e => e.ArrivalPortName, f => f.Address.City());
        RuleFor(e => e.DeparturePortName, f => f.Address.City());
    }
}