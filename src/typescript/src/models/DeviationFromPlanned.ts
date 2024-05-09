/**
 * Represents the "Deviation From Planned" section of SVD.
 */
export type DeviationFromPlanned = {
    /**
     * Description of why the ship has deviated from the planned voyage.
     */
    Reason: string;

    /**
     * Latitude (geographical coordinate) of the location of the ship at the time of deviation.
     */
    Latitude: number;

    /**
     * Longitude (geographical coordinate) of the location of the ship at the time of deviation.
     */
    Longitude: number;

    /**
     * Date and time when the ship started its deviation from the planned voyage.
     */
    ShipDeviationStartedTime: Date;

    /**
     * Date and time when the ship stopped its deviation from the planned voyage.
     */
    ShipDeviationStoppedTime: Date;
};
