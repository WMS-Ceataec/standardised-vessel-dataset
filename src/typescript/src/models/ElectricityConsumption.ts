/**
 * Represents the "Electricity Consumption" section of the SVD.
 */
export type ElectricityConsumption = {
  /**
   * Boiler electricity consumption, measured in kilowatt hours since last reporting.
   */
  BoilerElectricityConsumption: number;

  /**
   * The measure of the production of a generator not used for propulsion, in kilowatt hours since last reporting.
   */
  GeneratorProduction: number;

  /**
   * The permitted quantity of electricity consumption during report duration which can be used to offset/correct emissions calculations, measured in kilowatt hours.
   */
  OffsetElectricityConsumption: number;

  /**
   * Power consumption from generator used for re-liquification, related to the plant (cooling of cargo), measured in kilowatt hours since last reporting.
   */
  PowerConsumptionForPlant: number;

  /**
   * Electrical power generated for Cargo Cooling, measured in kilowatt-hours.
   */
  ElectricalForCargoCooling: number;

  /**
   * Electrical power generated for Discharge Pump, measured in kilowatt-hours.
   */
  ElectricalForDischargePump: number;

  /**
   * Electrical power generated for Reefer Containers, measured in kilowatt-hours.
   */
  ElectricalForReeferContainers: number;

  /**
   * Amount of electrical power received from on-shore power supply when in port, measured in kilowatt-hours.
   */
  ElectricalFromOnShorePowerSupply: number;

  /**
   * Amount of electrical power received from zero emissions technologies (solar panels etc), measured in kilowatt-hours.
   */
  ElectricalFromZeroEmissionsTechnologies: number;

  /**
   * A code representing the type of fuel used for electrical work generated for cargo cooling.
   */
  FuelTypeUsedForCargoCooling: string;

  /**
   * A code representing the type of fuel used for electrical work generated for discharge pump.
   */
  FuelTypeUsedForDischargePump: string;

  /**
   * A code representing the type of fuel used for electrical work generated for reefer containers.
   */
  FuelTypeUsedForReeferContainers: string;

  /**
   * A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Cargo Cooling, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
   */
  FuelOilConsumptionForCargoCooling: number;

  /**
   * A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Discharge Pump, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
   */
  FuelOilConsumptionForDischargePump: number;

  /**
   * A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Reefer Containers, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
   */
  FuelOilConsumptionForReeferContainers: number;
};
