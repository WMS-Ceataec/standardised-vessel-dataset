/**
 * Represents the "Port Information" section of SVD.
 */
export type PortInformation = {
    /**
     * The code representing the port from which the ship departs.
     */
    DeparturePortCode: string;

    /**
     * The description of the port from which the ship departs.
     */
    DeparturePortDescription: string;

    /**
     * The date and time the ship departs from the port.
     */
    DepartureDateTime: string;

    /**
     * The code representing the port where the ship arrives.
     */
    ArrivalPortCode: string;

    /**
     * The name and country of the port where the ship arrives.
     */
    ArrivalPortDescription: string;

    /**
     * The name, number or description used to identify a Pilot boarding place, the location offshore where a pilot may board a vessel in preparation to piloting it through local waters. (IHO Concept register).
     */
    PilotBoardingPlaceName: string;

    /**
     * The location (geographical coordinates) of the Pilot boarding place.
     */
    PilotBoardingPlaceLocation: string;

    /**
     * A name used to identify a berth. A berth is defined as a place, generally named or numbered, where a vessel may moor or anchor. (IHO Concept register).
     */
    BerthName: string;
};