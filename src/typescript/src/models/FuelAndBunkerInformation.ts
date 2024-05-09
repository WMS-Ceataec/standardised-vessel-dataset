/**
 * Represents the "Fuel and Bunker Information" section of SVD.
 */
export type FuelAndBunkerInformation = {
    /**
     * Code representing the type of bunkered fuel.
     */
    FuelType: string;

    /**
     * Identification number for the Bunker Delivery Note (BDN) associated with the fuel provided.
     */
    BunkerDeliveryNoteNumber: string;

    /**
     * Date and time as given in the BDN, e.g., the time when all fuel has been received.
     */
    BunkerDeliveryDateTime: Date;

    /**
     * Amount of fuel received during bunkering, measured in metric tonnes.
     */
    FuelBunkered: number;

    /**
     * Mass of fuel, measured in metric tons (mt).
     */
    FuelMass: number;

    /**
     * Density of fuel at 15 degrees Celsius, measured in metric tons per cubic metre (mt/m3).
     */
    FuelDensity: number;

    /**
     * Sulphur content in fuel, measured in percentage per millimetre (% m/m).
     */
    FuelSulphurContent: number;

    /**
     * Viscosity of fuel, measured in centistokes (cSt).
     */
    FuelViscosity: number;

    /**
     * Water content of fuel, measured in % volume per volume (% V/V).
     */
    FuelWaterContent: number;

    /**
     * Higher heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg).
     */
    FuelHigherHeatingValue: number;

    /**
     * Lower heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg).
     */
    FuelLowerHeatingValue: number;

    /**
     * Information referring to the fuel grade, quality and composition.
     */
    FuelGrade: string;

    /**
     * Code representing the port where the fuel is to be bunkered, according to a bunker delivery note.
     */
    FuelBunkerPort: string;

    /**
     * Name and country of the port where the fuel is to be bunkered, according to a bunker delivery note.
     */
    FuelBunkerPortName: string;

    /**
     * Carbon Dioxide (CO2) emissions, expressed in grams of CO2 per gram of fuel, gCO2/g.
     */
    FuelCarbonDioxideEmission: number;

    /**
     * Total fuel consumed, measured in metric tonnes since last reporting.
     */
    TotalFuelConsumed: number;

    /**
     * Fuel consumed by Main Engine, measured in metric tonnes since last reporting.
     */
    FuelConsumedByME: number;

    /**
     * Fuel consumed by diesel electric propulsion, measured in metric tonnes since last reporting.
     */
    FuelConsumedByDE: number;

    /**
     * Fuel consumed by Diesel Generator, measured in metric tonnes since last reporting.
     */
    FuelConsumedByDG: number;

    /**
     * Fuel consumed by Auxiliary Boiler, measured in metric tonnes since last reporting.
     */
    FuelConsumedByAuxiliaryBoiler: number;

    /**
     * Remaining fuel on board based on Engine Room log entries, measured in metric tonnes since last reporting.
     */
    FuelRemainingOnBoard: number;

    /**
     * Amount of sludge remaining onboard, measured in metric tonnes since last reporting.
     */
    SludgeRemainingOnBoard: number;
};
