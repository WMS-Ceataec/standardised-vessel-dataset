/**
 * Represents the "Fuel and Bunker Information" section of SVD.
 */
export type FuelAndBunkerInformation = {
  /**
   * A code representing the type of bunkered fuel.
   */
  FuelType: string;

  /**
   * A code representing the trade name of the fuel.
   */
  FuelTypeTradeName: string;

  /**
   * The identification number for the Bunker Delivery Note (BDN) associated with the fuel provided.
   */
  BunkerDeliveryNoteNumber: string;

  /**
   * The date and time as given in the BDN, e.g., the time when all fuel has been received.
   */
  BunkerDeliveryDateTime: Date;

  /**
   * Reference number from certification confirming that fuel received complies with GHG intensity limit under FuelEU regulations.
   */
  FuelProofOfSustainabilityReference: string;

  /**
   * The amount of fuel received during bunkering, measured in metric tonnes.
   */
  FuelBunkered: number;

  /**
   * Mass of fuel, measured in metric tonnes.
   */
  FuelMass: number;

  /**
   * Density of fuel at 15°C, measured in metric tons per cubic metre (mt/m3).
   */
  FuelDensity: number;

  /**
   * Sulphur content in fuel, measured in percentage per mass (% m/m).
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
   * Fuel calorific value reporting scheme code, which may differ depending on the reporting scheme.
   */
  FuelCalorificValueReportingSchemeCode: string;

  /**
   * Lower calorific value (LCV) of fuel, measured in megajoules per kilogram.
   */
  FuelLowerCalorificValue: number;

  /**
   * Information referring to the fuel grade, quality and composition.
   */
  FuelGrade: string;

  /**
   * Fuel GHG intensity (IMO) manually, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).
   */
  FuelGHGIntensityIMOManual: number;

  /**
   * Fuel GHG intensity (IMO) per voyage, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).
   */
  FuelGHGIntensityIMOVoyage: number;

  /**
   * Code representing the port where the fuel is to be bunkered, according to a bunker delivery note.
   */
  FuelBunkerPort: string;

  /**
   * Name and country of the port where the fuel is to be bunkered, according to a bunker delivery note.
   */
  FuelBunkerPortName: string;

  /**
   * Carbon Dioxide (CO2) emissions per gram of fuel, measured as grams of CO2 per gram (gCO2/g).
   */
  FuelCarbonDioxideEmission: number;

  /**
   * Total fuel consumed, measured in metric tonnes since last reporting.
   */
  TotalFuelConsumed: number;

  /**
   * Fuel consumed by Main Engine, measured in metric tonnes since last reporting.
   */
  FuelConsumedByMainEngine: number;

  /**
   * Fuel consumed by Diesel Electric Propulsion, measured in metric tonnes since last reporting.
   */
  FuelConsumedByDieselElectricPropulsion: number;

  /**
   * Fuel consumed by Diesel Generator, measured in metric tonnes since last reporting.
   */
  FuelConsumedByDieselGenerator: number;

  /**
   * Fuel consumed by Auxiliary Boiler, measured in metric tonnes since last reporting.
   */
  FuelConsumedByAuxiliaryBoiler: number;

  /**
   * Fuel consumed by Auxiliary Engine, measured in metric tonnes since last reporting.
   */
  FuelConsumedByAuxiliaryEngine: number;

  /**
   * Fuel consumed by Cargo Heating, measured in metric tonnes since last reporting.
   */
  FuelConsumedByCargoHeating: number;

  /**
   * Fuel consumed by Reefer Containers, measured in metric tonnes since last reporting.
   */
  FuelConsumedByReeferContainers: number;

  /**
   * Fuel consumed by Discharge Pump, measured in metric tonnes since last reporting.
   */
  FuelConsumedByDischargePump: number;

  /**
   * Fuel consumed by Other Fuel Consuming Devices, measured in metric tonnes since last reporting.
   */
  FuelConsumedByOtherDevices: number;

  /**
   * Remaining fuel on board based on Engine Room log entries, measured in metric tonnes.
   */
  FuelRemainingOnBoard: number;

  /**
   * Amount of sludge remaining onboard, measured in metric tonnes.
   */
  SludgeRemainingOnBoard: number;
};
