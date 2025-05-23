/**
* Represent the "Emissions" section of SVD
*/
export type Emissions = {
  /**
   * The total amount of Carbon Dioxide refers to the comprehensive sum of CO2, including its equivalents derived from all emissions 
   * (but without deducting the CO2 equivalent captured), quantified in metric tons of CO2 equivalent.
   */
  TotalCo2: number;

  /**
   * Proportion of Carbon Dioxide emissions that are emitted while at sea, taking into account the amount that is successfully captured, measured in percentage.
   */
  TotalCo2Percentage: number;

  /**
   * Total amount of Carbon Dioxide from fuels (tank-to-wake), measured in metric tons.
   */
  TotalCo2TankToWake: number;

  /**
   * Total amount of Carbon Dioxide equivalent captured, measured in metric tons.
   */
  TotalCo2Captured: number;

  /**
   * Total aggregated amount of Methane emitted, measured in metric tons.
   */
  TotalCh4: number;

  /**
   * The CO2 equivalent converted from CH4 emissions, measured in metric tons of CO2 equivalent.
   */
  TotalCh4ConvertedToCo2: number;

  /**
   * Total aggregated amount of Nitrous Oxide emitted, measured in metric tons.
   */
  TotalN2o: number;

  /**
   * The CO2 equivalent converted from N2O emissions, measured in metric tons of CO2 equivalent.
   */
  TotalN2oConvertedToCo2: number;

  /**
   * CH4 emission conversion factor, expressed in emissions per gram of fuel (gCH4/gfuel).
   */
  Ch4EmissionConversionFactor: number;

  /**
   * N2O emission conversion factor, expressed in emissions per gram of fuel (gN2O/gfuel).
   */
  N2oEmissionConversionFactor: number;
};
