/**
 * Represents the "Arrival Times" section of SVD.
 */
export type ArrivalTimes = {
  /**
   * The date and time the ship arrives at a specified location (Actual Time of Arrival, ATA).
   */
  Arrival: string;

  /**
   * The date and time the ship departs from a specified location (Actual Time of Departure, ATD).
   */
  Departure: string;

  /**
   * The date and time the ship estimates to reach the specified location in port (Estimated Time of Arrival, ETA).
   */
  LocationEta: string;

  /**
   * The actual date and time the ship actually reached the specified location in port.
   */
  LocationActual: string;

  /**
   * The date and time the ship estimates to reach the Pilot Boarding Place.
   */
  PilotBoardingPlaceEta: string;

  /**
   * The actual date and time the ship actually reached the Pilot Boarding Place.
   */
  PilotBoardingPlaceActual: string;

  /**
   * The date and time the ship estimates to reach the VTS (Vessel Traffic Service) area.
   */
  VtsEta: string;

  /**
   * The actual date and time the ship actually reached the VTS (Vessel Traffic Service) area.
   */
  VtsActual: string;

  /**
   * The date and time the ship is estimated to arrive at the next port of call.
   */
  NextPortEta: string;

  /**
   * Travel time from departed port to destination port in hours.
   */
  VoyageTime: number;
};