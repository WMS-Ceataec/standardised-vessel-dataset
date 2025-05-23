/**
 * Represents the "Port Information" section of SVD.
 */
export type PortInformation = {
  /**
   * The code representing the port from which the ship departs.
   */
  DeparturePortCode: string;

  /**
   * The name and country of the port from which the ship departs.
   */
  DeparturePortName: string;

  /**
   * The code representing the port where the ship arrives.
   */
  ArrivalPortCode: string;

  /**
   * The name and country of the port where the ship arrives.
   */
  ArrivalPortName: string;

  /**
   * Reporting jurisdiction covering the arriving port for this voyage. Used to define mandatory reporting requirements related to ship emissions for different voyages.
   */
  InboundPortJurisdictionCode: string;

  /**
   * Reporting jurisdiction covering the departure port for this voyage. Used to define mandatory reporting requirements related to ship emissions for different voyages.
   */
  OutboundPortJurisdictionCode: string;

  /**
   * The name, number, or description used to identify a Pilot boarding place, the location offshore where a pilot may board a vessel in preparation to piloting it through local waters.
   */
  PilotBoardingPlaceName: string;

  /**
   * The location (geographical coordinates) of the Pilot boarding place.
   */
  PilotBoardingPlaceLocation: string;

  /**
   * A name used to identify a berth. A berth is defined as a place, generally named or numbered, where a vessel may moor or anchor.
   */
  BerthName: string;
};