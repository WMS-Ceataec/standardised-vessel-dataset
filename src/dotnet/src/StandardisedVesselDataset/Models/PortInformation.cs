namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Port and Route Information section of SVD
/// </summary>
public class PortInformation
{
    /// <summary>
    /// The code representing the port from which the ship departs.
    /// </summary>
    public string DeparturePortCode { get; init; }
    /// <summary>
    /// The description of the port from which the ship departs.
    /// </summary>
    public string DeparturePortDescription { get; init; }
    /// <summary>
    /// The date and time the ship departs from the port.
    /// </summary>
    public string ArrivalPortCode { get; init; }
    /// <summary>
    /// The name and country of the port where the ship arrives.
    /// </summary>
    public string ArrivalPortDescription { get; init; }
    /// <summary>
    /// The name, number or description used to identify a Pilot boarding place, the location offshore where a pilot may board a vessel in preparation to piloting it through local waters. (IHO Concept register).
    /// </summary>
    public string PilotBoardingPlaceName { get; init; }
    /// <summary>
    /// The location (geographical coordinates) of the Pilot boarding place.
    /// </summary>
    public string PilotBoardingPlaceLocation { get; init; }
    /// <summary>
    /// A name used to identify a berth. A berth is defined as a place, generally named or numbered, where a vessel may moor or anchor. (IHO Concept register).
    /// </summary>
    public string BerthName { get; init; }
}