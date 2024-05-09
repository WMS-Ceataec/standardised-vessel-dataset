/**
 * Represents the "Cylinder Lube Oil Information" section of SVD
 */
export type CylinderLubeOilInformation = {
    /**
     * Cylinder lube oil remaining on board based on Engine Room log entries, measured in metric tons.
     */
    RemainingOnBoard: number;

    /**
     * Rate of feed of lube oil into the cylinder, measured in grams per kilowatt hour (g/kWh).
     */
    FeedRate: number;

    /**
     * Lube oil consumption in grams per hour per unit of output measured in kilowatts of the engine (g/kWh).
     */
    Consumption: number;

    /**
     * Lube oil received during bunkering, measured in metric tons.
     */
    ReceivedDuringBunkering: number;
};
