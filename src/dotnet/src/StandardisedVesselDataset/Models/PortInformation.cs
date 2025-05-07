namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the "Port Information" section of SVD
/// </summary>
public class PortInformation
{
    /// <summary>
    /// The code representing the port from which the ship departs.
    /// </summary>
    public string DeparturePortCode { get; init; }

    /// <summary>
    /// The name and country of the port from which the ship departs.
    /// </summary>
    public string DeparturePortName { get; init; }

    /// <summary>
    /// The code representing the port where the ship arrives.
    /// </summary>
    public string ArrivalPortCode { get; init; }

    /// <summary>
    /// The name and country of the port where the ship arrives.
    /// </summary>
    public string ArrivalPortName { get; init; }

    /// <summary>
    /// Reporting jurisdiction covering the arriving port for this voyage. Used to define mandatory reporting requirements related to ship emissions for different voyages.
    /// </summary>
    public string InboundPortJurisdictionCode { get; init; }

    /// <summary>
    /// Reporting jurisdiction covering the departure port for this voyage. Used to define mandatory reporting requirements related to ship emissions for different voyages.
    /// </summary>
    public string OutboundPortJurisdictionCode { get; init; }

    /// <summary>
    /// The name, number, or description used to identify a Pilot boarding place, the location offshore where a pilot may board a vessel in preparation to piloting it through local waters.
    /// </summary>
    public string PilotBoardingPlaceName { get; init; }

    /// <summary>
    /// The location (geographical coordinates) of the Pilot boarding place.
    /// </summary>
    public string PilotBoardingPlaceLocation { get; init; }

    /// <summary>
    /// A name used to identify a berth. A berth is defined as a place, generally named or numbered, where a vessel may moor or anchor.
    /// </summary>
    public string BerthName { get; init; }
}
