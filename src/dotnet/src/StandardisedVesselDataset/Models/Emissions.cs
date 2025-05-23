namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents emissions data including CO2, CH4, and N2O metrics and conversion factors.
/// </summary>
public class Emissions
{
    /// <summary>
    /// The total amount of Carbon Dioxide refers to the comprehensive sum of CO2, including its equivalents derived from all emissions 
    /// (but without deducting the CO2 equivalent captured), quantified in metric tons of CO2 equivalent.
    /// </summary>
    public double TotalCo2 { get; set; }

    /// <summary>
    /// Proportion of Carbon Dioxide emissions that are emitted while at sea, taking into account the amount that is successfully captured, measured in percentage.
    /// </summary>
    public double TotalCo2Percentage { get; set; }

    /// <summary>
    /// Total amount of Carbon Dioxide from fuels (tank-to-wake), measured in metric tons.
    /// </summary>
    public double TotalCo2TankToWake { get; set; }

    /// <summary>
    /// Total amount of Carbon Dioxide equivalent captured, measured in metric tons.
    /// </summary>
    public double TotalCo2Captured { get; set; }

    /// <summary>
    /// Total aggregated amount of Methane emitted, measured in metric tons.
    /// </summary>
    public double TotalCh4 { get; set; }

    /// <summary>
    /// The CO2 equivalent converted from CH4 emissions, measured in metric tons of CO2 equivalent.
    /// </summary>
    public double TotalCh4ConvertedToCo2 { get; set; }

    /// <summary>
    /// Total aggregated amount of Nitrous Oxide emitted, measured in metric tons.
    /// </summary>
    public double TotalN2o { get; set; }

    /// <summary>
    /// The CO2 equivalent converted from N2O emissions, measured in metric tons of CO2 equivalent.
    /// </summary>
    public double TotalN2oConvertedToCo2 { get; set; }

    /// <summary>
    /// CH4 emission conversion factor, expressed in emissions per gram of fuel (gCH4/gfuel).
    /// </summary>
    public double Ch4EmissionConversionFactor { get; set; }

    /// <summary>
    /// N2O emission conversion factor, expressed in emissions per gram of fuel (gN2O/gfuel).
    /// </summary>
    public double N2oEmissionConversionFactor { get; set; }
}
