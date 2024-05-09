/**
 * Represents the "Arrival Times" section of SVD.
 */
export type ArrivalTimes = {
    /**
     * The date and time the ship estimates to reach the specified location in port.
     */
    Eta: Date;

    /**
     * The actual date and time the ship actually reached the specified location in port.
     */
    Actual: Date;

    /**
     * The date and time the ship estimates to reach the Pilot Boarding Place.
     */
    PilotBoardingPlaceEta: Date;

    /**
     * The actual date and time the ship actually reached the Pilot Boarding Place.
     */
    PilotBoardingPlaceActual: Date;

    /**
     * The date and time the ship estimates to reach the VTS area.
     */
    VtsEta: Date;

    /**
     * The actual date and time the ship actually reached the VTS area.
     */
    VtsActual: Date;

    /**
     * The date and time the ship is estimated to arrive at the next port of call.
     */
    NextPortEta: Date;

    /**
     * Travel time from departed port to destination port in hours.
     */
    VoyageTime: number;
};
