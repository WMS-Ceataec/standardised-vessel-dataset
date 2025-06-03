#pragma once

namespace svd {
namespace models {

/// <summary>
/// Represents emissions data including CO2, CH4, and N2O metrics and conversion factors.
/// </summary>
class Emissions 
{
private:
    double m_totalCo2;
    double m_totalCo2Percentage;
    double m_totalCo2TankToWake;
    double m_totalCo2Captured;
    double m_totalCh4;
    double m_totalCh4ConvertedToCo2;
    double m_totalN2o;
    double m_totalN2oConvertedToCo2;
    double m_ch4EmissionConversionFactor;
    double m_n2oEmissionConversionFactor;

public:
    Emissions() = default;    /// <summary>
    /// The total amount of Carbon Dioxide refers to the comprehensive sum of CO2, including its equivalents derived from all emissions 
    /// (but without deducting the CO2 equivalent captured), quantified in metric tons of CO2 equivalent.
    /// </summary>
    double getTotalCo2() const { return m_totalCo2; }
    void setTotalCo2(double totalCo2) { m_totalCo2 = totalCo2; }

    /// <summary>
    /// Proportion of Carbon Dioxide emissions that are emitted while at sea, taking into account the amount that is successfully captured, measured in percentage.
    /// </summary>
    double getTotalCo2Percentage() const { return m_totalCo2Percentage; }
    void setTotalCo2Percentage(double totalCo2Percentage) { m_totalCo2Percentage = totalCo2Percentage; }

    /// <summary>
    /// Total amount of Carbon Dioxide from fuels (tank-to-wake), measured in metric tons.
    /// </summary>
    double getTotalCo2TankToWake() const { return m_totalCo2TankToWake; }
    void setTotalCo2TankToWake(double totalCo2TankToWake) { m_totalCo2TankToWake = totalCo2TankToWake; }

    /// <summary>
    /// Total amount of Carbon Dioxide equivalent captured, measured in metric tons.
    /// </summary>
    double getTotalCo2Captured() const { return m_totalCo2Captured; }
    void setTotalCo2Captured(double totalCo2Captured) { m_totalCo2Captured = totalCo2Captured; }

    /// <summary>
    /// Total aggregated amount of Methane emitted, measured in metric tons.
    /// </summary>
    double getTotalCh4() const { return m_totalCh4; }
    void setTotalCh4(double totalCh4) { m_totalCh4 = totalCh4; }

    /// <summary>
    /// The CO2 equivalent converted from CH4 emissions, measured in metric tons of CO2 equivalent.
    /// </summary>
    double getTotalCh4ConvertedToCo2() const { return m_totalCh4ConvertedToCo2; }
    void setTotalCh4ConvertedToCo2(double totalCh4ConvertedToCo2) { m_totalCh4ConvertedToCo2 = totalCh4ConvertedToCo2; }

    /// <summary>
    /// Total aggregated amount of Nitrous Oxide emitted, measured in metric tons.
    /// </summary>
    double getTotalN2o() const { return m_totalN2o; }
    void setTotalN2o(double totalN2o) { m_totalN2o = totalN2o; }

    /// <summary>
    /// The CO2 equivalent converted from N2O emissions, measured in metric tons of CO2 equivalent.
    /// </summary>
    double getTotalN2oConvertedToCo2() const { return m_totalN2oConvertedToCo2; }
    void setTotalN2oConvertedToCo2(double totalN2oConvertedToCo2) { m_totalN2oConvertedToCo2 = totalN2oConvertedToCo2; }

    /// <summary>
    /// CH4 emission conversion factor, expressed in emissions per gram of fuel (gCH4/gfuel).
    /// </summary>
    double getCh4EmissionConversionFactor() const { return m_ch4EmissionConversionFactor; }
    void setCh4EmissionConversionFactor(double ch4EmissionConversionFactor) { m_ch4EmissionConversionFactor = ch4EmissionConversionFactor; }    /// <summary>
    /// N2O emission conversion factor, expressed in emissions per gram of fuel (gN2O/gfuel).
    /// </summary>
    double getN2oEmissionConversionFactor() const { return m_n2oEmissionConversionFactor; }
    void setN2oEmissionConversionFactor(double n2oEmissionConversionFactor) { m_n2oEmissionConversionFactor = n2oEmissionConversionFactor; }
};

} // namespace models
} // namespace svd
