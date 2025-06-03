#pragma once

#include <string>

namespace svd {
namespace models {

/// <summary>
/// Represents the "Electricity Consumption" section of the SVD.
/// </summary>
class ElectricityConsumption
{
private:
    double m_boilerElectricityConsumption;
    double m_generatorProduction;
    double m_offsetElectricityConsumption;
    double m_powerConsumptionForPlant;
    double m_electricalForCargoCooling;
    double m_electricalForDischargePump;
    double m_electricalForReeferContainers;
    double m_electricalFromOnShorePowerSupply;
    double m_electricalFromZeroEmissionsTechnologies;
    std::string m_fuelTypeUsedForCargoCooling;
    std::string m_fuelTypeUsedForDischargePump;
    std::string m_fuelTypeUsedForReeferContainers;
    double m_fuelOilConsumptionForCargoCooling;
    double m_fuelOilConsumptionForDischargePump;
    double m_fuelOilConsumptionForReeferContainers;

public:
    ElectricityConsumption() = default;

    /// <summary>
    /// Boiler electricity consumption, measured in kilowatt hours since last reporting.
    /// </summary>
    double getBoilerElectricityConsumption() const { return m_boilerElectricityConsumption; }
    void setBoilerElectricityConsumption(double boilerElectricityConsumption) { m_boilerElectricityConsumption = boilerElectricityConsumption; }

    /// <summary>
    /// The measure of the production of a generator not used for propulsion, in kilowatt hours since last reporting.
    /// </summary>
    double getGeneratorProduction() const { return m_generatorProduction; }
    void setGeneratorProduction(double generatorProduction) { m_generatorProduction = generatorProduction; }

    /// <summary>
    /// The permitted quantity of electricity consumption during report duration which can be used to offset/correct emissions calculations, measured in kilowatt hours.
    /// </summary>
    double getOffsetElectricityConsumption() const { return m_offsetElectricityConsumption; }
    void setOffsetElectricityConsumption(double offsetElectricityConsumption) { m_offsetElectricityConsumption = offsetElectricityConsumption; }

    /// <summary>
    /// Power consumption from generator used for re-liquification, related to the plant (cooling of cargo), measured in kilowatt hours since last reporting.
    /// </summary>
    double getPowerConsumptionForPlant() const { return m_powerConsumptionForPlant; }
    void setPowerConsumptionForPlant(double powerConsumptionForPlant) { m_powerConsumptionForPlant = powerConsumptionForPlant; }

    /// <summary>
    /// Electrical power generated for Cargo Cooling, measured in kilowatt-hours.
    /// </summary>
    double getElectricalForCargoCooling() const { return m_electricalForCargoCooling; }
    void setElectricalForCargoCooling(double electricalForCargoCooling) { m_electricalForCargoCooling = electricalForCargoCooling; }

    /// <summary>
    /// Electrical power generated for Discharge Pump, measured in kilowatt-hours.
    /// </summary>
    double getElectricalForDischargePump() const { return m_electricalForDischargePump; }
    void setElectricalForDischargePump(double electricalForDischargePump) { m_electricalForDischargePump = electricalForDischargePump; }

    /// <summary>
    /// Electrical power generated for Reefer Containers, measured in kilowatt-hours.
    /// </summary>
    double getElectricalForReeferContainers() const { return m_electricalForReeferContainers; }
    void setElectricalForReeferContainers(double electricalForReeferContainers) { m_electricalForReeferContainers = electricalForReeferContainers; }

    /// <summary>
    /// Amount of electrical power received from on-shore power supply when in port, measured in kilowatt-hours.
    /// </summary>
    double getElectricalFromOnShorePowerSupply() const { return m_electricalFromOnShorePowerSupply; }
    void setElectricalFromOnShorePowerSupply(double electricalFromOnShorePowerSupply) { m_electricalFromOnShorePowerSupply = electricalFromOnShorePowerSupply; }

    /// <summary>
    /// Amount of electrical power received from zero emissions technologies (solar panels etc), measured in kilowatt-hours.
    /// </summary>
    double getElectricalFromZeroEmissionsTechnologies() const { return m_electricalFromZeroEmissionsTechnologies; }
    void setElectricalFromZeroEmissionsTechnologies(double electricalFromZeroEmissionsTechnologies) { m_electricalFromZeroEmissionsTechnologies = electricalFromZeroEmissionsTechnologies; }

    /// <summary>
    /// A code representing the type of fuel used for electrical work generated for cargo cooling.
    /// </summary>
    const std::string& getFuelTypeUsedForCargoCooling() const { return m_fuelTypeUsedForCargoCooling; }
    void setFuelTypeUsedForCargoCooling(const std::string& fuelTypeUsedForCargoCooling) { m_fuelTypeUsedForCargoCooling = fuelTypeUsedForCargoCooling; }

    /// <summary>
    /// A code representing the type of fuel used for electrical work generated for discharge pump.
    /// </summary>
    const std::string& getFuelTypeUsedForDischargePump() const { return m_fuelTypeUsedForDischargePump; }
    void setFuelTypeUsedForDischargePump(const std::string& fuelTypeUsedForDischargePump) { m_fuelTypeUsedForDischargePump = fuelTypeUsedForDischargePump; }

    /// <summary>
    /// A code representing the type of fuel used for electrical work generated for reefer containers.
    /// </summary>
    const std::string& getFuelTypeUsedForReeferContainers() const { return m_fuelTypeUsedForReeferContainers; }
    void setFuelTypeUsedForReeferContainers(const std::string& fuelTypeUsedForReeferContainers) { m_fuelTypeUsedForReeferContainers = fuelTypeUsedForReeferContainers; }

    /// <summary>
    /// A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Cargo Cooling, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
    /// </summary>
    double getFuelOilConsumptionForCargoCooling() const { return m_fuelOilConsumptionForCargoCooling; }
    void setFuelOilConsumptionForCargoCooling(double fuelOilConsumptionForCargoCooling) { m_fuelOilConsumptionForCargoCooling = fuelOilConsumptionForCargoCooling; }

    /// <summary>
    /// A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Discharge Pump, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
    /// </summary>
    double getFuelOilConsumptionForDischargePump() const { return m_fuelOilConsumptionForDischargePump; }
    void setFuelOilConsumptionForDischargePump(double fuelOilConsumptionForDischargePump) { m_fuelOilConsumptionForDischargePump = fuelOilConsumptionForDischargePump; }

    /// <summary>
    /// A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Reefer Containers, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
    /// </summary>
    double getFuelOilConsumptionForReeferContainers() const { return m_fuelOilConsumptionForReeferContainers; }
    void setFuelOilConsumptionForReeferContainers(double fuelOilConsumptionForReeferContainers) { m_fuelOilConsumptionForReeferContainers = fuelOilConsumptionForReeferContainers; }
};

} // namespace models
} // namespace svd
