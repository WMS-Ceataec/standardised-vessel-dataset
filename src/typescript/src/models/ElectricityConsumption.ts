/**
 * Represents the "Electricity Consumption" section of the SVD.
 */
export type ElectricityConsumption = {
    /**
     * Boiler electricity consumption, measured in kilowatt hours since last reporting.
     */
    BoilerElectricityConsumption: number;

    /**
     * Measure of the production of a generator not used for propulsion, in kilowatt hours since last reporting.
     */
    GeneratorProduction: number;

    /**
     * Permitted quantity of electricity consumption during report duration which can be used to offset/correct emissions calculations, measured in kilowatt hours.
     */
    OffsetElectricityConsumption: number;

    /**
     * Power consumption from generator used for re-liquification, related to the plant (cooling of cargo), measured in kilowatt hours since last reporting.
     */
    PowerConsumptionForPlant: number;
};
