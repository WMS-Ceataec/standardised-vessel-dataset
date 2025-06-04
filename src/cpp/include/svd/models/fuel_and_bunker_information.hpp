#pragma once

#include <string>
#include <chrono>

namespace svd {
namespace models {

/// <summary>
/// Represents the "Fuel and Bunker Information" section of SVD.
/// </summary>
class FuelAndBunkerInformation 
{
private:
    std::string m_fuelType;
    std::string m_fuelTypeTradeName;
    std::string m_bunkerDeliveryNoteNumber;
    std::chrono::system_clock::time_point m_bunkerDeliveryDateTime;
    std::string m_fuelProofOfSustainabilityReference;
    double m_fuelBunkered;
    double m_fuelMass;
    double m_fuelDensity;
    double m_fuelSulphurContent;
    double m_fuelViscosity;
    double m_fuelWaterContent;
    double m_fuelHigherHeatingValue;
    double m_fuelLowerHeatingValue;
    std::string m_fuelCalorificValueReportingSchemeCode;
    double m_fuelLowerCalorificValue;
    std::string m_fuelGrade;
    double m_fuelGhgIntensityImoManual;
    double m_fuelGhgIntensityImoVoyage;
    std::string m_fuelBunkerPort;
    std::string m_fuelBunkerPortName;
    double m_fuelCarbonDioxideEmission;
    double m_totalFuelConsumed;
    double m_fuelConsumedByMainEngine;
    double m_fuelConsumedByDieselElectricPropulsion;
    double m_fuelConsumedByDieselGenerator;
    double m_fuelConsumedByAuxiliaryBoiler;
    double m_fuelConsumedByAuxiliaryEngine;
    double m_fuelConsumedByCargoHeating;
    double m_fuelConsumedByReeferContainers;
    double m_fuelConsumedByDischargePump;
    double m_fuelConsumedByOtherDevices;
    double m_fuelRemainingOnBoard;
    double m_sludgeRemainingOnBoard;

public:
    FuelAndBunkerInformation() = default;    /// <summary>
    /// A code representing the type of bunkered fuel.
    /// </summary>
    const std::string& getFuelType() const { return m_fuelType; }
    void setFuelType(const std::string& fuelType) { m_fuelType = fuelType; }

    /// <summary>
    /// A code representing the trade name of the fuel.
    /// </summary>
    const std::string& getFuelTypeTradeName() const { return m_fuelTypeTradeName; }
    void setFuelTypeTradeName(const std::string& fuelTypeTradeName) { m_fuelTypeTradeName = fuelTypeTradeName; }

    /// <summary>
    /// The identification number for the Bunker Delivery Note (BDN) associated with the fuel provided.
    /// </summary>
    const std::string& getBunkerDeliveryNoteNumber() const { return m_bunkerDeliveryNoteNumber; }
    void setBunkerDeliveryNoteNumber(const std::string& bunkerDeliveryNoteNumber) { m_bunkerDeliveryNoteNumber = bunkerDeliveryNoteNumber; }

    /// <summary>
    /// The date and time as given in the BDN, e.g., the time when all fuel has been received.
    /// </summary>
    const std::chrono::system_clock::time_point& getBunkerDeliveryDateTime() const { return m_bunkerDeliveryDateTime; }
    void setBunkerDeliveryDateTime(const std::chrono::system_clock::time_point& bunkerDeliveryDateTime) { m_bunkerDeliveryDateTime = bunkerDeliveryDateTime; }

    /// <summary>
    /// Reference number from certification confirming that fuel received complies with GHG intensity limit under FuelEU regulations.
    /// </summary>
    const std::string& getFuelProofOfSustainabilityReference() const { return m_fuelProofOfSustainabilityReference; }
    void setFuelProofOfSustainabilityReference(const std::string& fuelProofOfSustainabilityReference) { m_fuelProofOfSustainabilityReference = fuelProofOfSustainabilityReference; }    /// <summary>
    /// The amount of fuel received during bunkering, measured in metric tonnes.
    /// </summary>
    double getFuelBunkered() const { return m_fuelBunkered; }
    void setFuelBunkered(double fuelBunkered) { m_fuelBunkered = fuelBunkered; }

    /// <summary>
    /// Mass of fuel, measured in metric tonnes.
    /// </summary>
    double getFuelMass() const { return m_fuelMass; }
    void setFuelMass(double fuelMass) { m_fuelMass = fuelMass; }

    /// <summary>
    /// Density of fuel at 15°C, measured in metric tons per cubic metre (mt/m3).
    /// </summary>
    double getFuelDensity() const { return m_fuelDensity; }
    void setFuelDensity(double fuelDensity) { m_fuelDensity = fuelDensity; }

    /// <summary>
    /// Sulphur content in fuel, measured in percentage per mass (% m/m).
    /// </summary>
    double getFuelSulphurContent() const { return m_fuelSulphurContent; }
    void setFuelSulphurContent(double fuelSulphurContent) { m_fuelSulphurContent = fuelSulphurContent; }

    /// <summary>
    /// Viscosity of fuel, measured in centistokes (cSt).
    /// </summary>
    double getFuelViscosity() const { return m_fuelViscosity; }
    void setFuelViscosity(double fuelViscosity) { m_fuelViscosity = fuelViscosity; }

    /// <summary>
    /// Water content of fuel, measured in % volume per volume (% V/V).
    /// </summary>
    double getFuelWaterContent() const { return m_fuelWaterContent; }
    void setFuelWaterContent(double fuelWaterContent) { m_fuelWaterContent = fuelWaterContent; }

    /// <summary>
    /// Higher heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg).
    /// </summary>
    double getFuelHigherHeatingValue() const { return m_fuelHigherHeatingValue; }
    void setFuelHigherHeatingValue(double fuelHigherHeatingValue) { m_fuelHigherHeatingValue = fuelHigherHeatingValue; }    /// <summary>
    /// Lower heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg).
    /// </summary>
    double getFuelLowerHeatingValue() const { return m_fuelLowerHeatingValue; }
    void setFuelLowerHeatingValue(double fuelLowerHeatingValue) { m_fuelLowerHeatingValue = fuelLowerHeatingValue; }

    /// <summary>
    /// Fuel calorific value reporting scheme code, which may differ depending on the reporting scheme.
    /// </summary>
    const std::string& getFuelCalorificValueReportingSchemeCode() const { return m_fuelCalorificValueReportingSchemeCode; }
    void setFuelCalorificValueReportingSchemeCode(const std::string& fuelCalorificValueReportingSchemeCode) { m_fuelCalorificValueReportingSchemeCode = fuelCalorificValueReportingSchemeCode; }

    /// <summary>
    /// Lower calorific value (LCV) of fuel, measured in megajoules per kilogram.
    /// </summary>
    double getFuelLowerCalorificValue() const { return m_fuelLowerCalorificValue; }
    void setFuelLowerCalorificValue(double fuelLowerCalorificValue) { m_fuelLowerCalorificValue = fuelLowerCalorificValue; }

    /// <summary>
    /// Information referring to the fuel grade, quality and composition.
    /// </summary>
    const std::string& getFuelGrade() const { return m_fuelGrade; }
    void setFuelGrade(const std::string& fuelGrade) { m_fuelGrade = fuelGrade; }

    /// <summary>
    /// Fuel GHG intensity (IMO) manually, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).
    /// </summary>
    double getFuelGHGIntensityIMOManual() const { return m_fuelGhgIntensityImoManual; }
    void setFuelGHGIntensityIMOManual(double fuelGhgIntensityImoManual) { m_fuelGhgIntensityImoManual = fuelGhgIntensityImoManual; }

    /// <summary>
    /// Fuel GHG intensity (IMO) per voyage, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).
    /// </summary>
    double getFuelGHGIntensityIMOVoyage() const { return m_fuelGhgIntensityImoVoyage; }
    void setFuelGHGIntensityIMOVoyage(double fuelGhgIntensityImoVoyage) { m_fuelGhgIntensityImoVoyage = fuelGhgIntensityImoVoyage; }

    /// <summary>
    /// Code representing the port where the fuel is to be bunkered, according to a bunker delivery note.
    /// </summary>
    const std::string& getFuelBunkerPort() const { return m_fuelBunkerPort; }
    void setFuelBunkerPort(const std::string& fuelBunkerPort) { m_fuelBunkerPort = fuelBunkerPort; }

    /// <summary>
    /// Name and country of the port where the fuel is to be bunkered, according to a bunker delivery note.
    /// </summary>
    const std::string& getFuelBunkerPortName() const { return m_fuelBunkerPortName; }
    void setFuelBunkerPortName(const std::string& fuelBunkerPortName) { m_fuelBunkerPortName = fuelBunkerPortName; }    /// <summary>
    /// Carbon Dioxide (CO2) emissions per gram of fuel, measured as grams of CO2 per gram (gCO2/g).
    /// </summary>
    double getFuelCarbonDioxideEmission() const { return m_fuelCarbonDioxideEmission; }
    void setFuelCarbonDioxideEmission(double fuelCarbonDioxideEmission) { m_fuelCarbonDioxideEmission = fuelCarbonDioxideEmission; }

    /// <summary>
    /// Total fuel consumed, measured in metric tonnes since last reporting.
    /// </summary>
    double getTotalFuelConsumed() const { return m_totalFuelConsumed; }
    void setTotalFuelConsumed(double totalFuelConsumed) { m_totalFuelConsumed = totalFuelConsumed; }

    /// <summary>
    /// Fuel consumed by Main Engine, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByMainEngine() const { return m_fuelConsumedByMainEngine; }
    void setFuelConsumedByMainEngine(double fuelConsumedByMainEngine) { m_fuelConsumedByMainEngine = fuelConsumedByMainEngine; }

    /// <summary>
    /// Fuel consumed by Diesel Electric Propulsion, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByDieselElectricPropulsion() const { return m_fuelConsumedByDieselElectricPropulsion; }
    void setFuelConsumedByDieselElectricPropulsion(double fuelConsumedByDieselElectricPropulsion) { m_fuelConsumedByDieselElectricPropulsion = fuelConsumedByDieselElectricPropulsion; }

    /// <summary>
    /// Fuel consumed by Diesel Generator, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByDieselGenerator() const { return m_fuelConsumedByDieselGenerator; }
    void setFuelConsumedByDieselGenerator(double fuelConsumedByDieselGenerator) { m_fuelConsumedByDieselGenerator = fuelConsumedByDieselGenerator; }

    /// <summary>
    /// Fuel consumed by Auxiliary Boiler, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByAuxiliaryBoiler() const { return m_fuelConsumedByAuxiliaryBoiler; }
    void setFuelConsumedByAuxiliaryBoiler(double fuelConsumedByAuxiliaryBoiler) { m_fuelConsumedByAuxiliaryBoiler = fuelConsumedByAuxiliaryBoiler; }

    /// <summary>
    /// Fuel consumed by Auxiliary Engine, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByAuxiliaryEngine() const { return m_fuelConsumedByAuxiliaryEngine; }
    void setFuelConsumedByAuxiliaryEngine(double fuelConsumedByAuxiliaryEngine) { m_fuelConsumedByAuxiliaryEngine = fuelConsumedByAuxiliaryEngine; }

    /// <summary>
    /// Fuel consumed by Cargo Heating, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByCargoHeating() const { return m_fuelConsumedByCargoHeating; }
    void setFuelConsumedByCargoHeating(double fuelConsumedByCargoHeating) { m_fuelConsumedByCargoHeating = fuelConsumedByCargoHeating; }

    /// <summary>
    /// Fuel consumed by Reefer Containers, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByReeferContainers() const { return m_fuelConsumedByReeferContainers; }
    void setFuelConsumedByReeferContainers(double fuelConsumedByReeferContainers) { m_fuelConsumedByReeferContainers = fuelConsumedByReeferContainers; }

    /// <summary>
    /// Fuel consumed by Discharge Pump, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByDischargePump() const { return m_fuelConsumedByDischargePump; }
    void setFuelConsumedByDischargePump(double fuelConsumedByDischargePump) { m_fuelConsumedByDischargePump = fuelConsumedByDischargePump; }

    /// <summary>
    /// Fuel consumed by Other Fuel Consuming Devices, measured in metric tonnes since last reporting.
    /// </summary>
    double getFuelConsumedByOtherDevices() const { return m_fuelConsumedByOtherDevices; }
    void setFuelConsumedByOtherDevices(double fuelConsumedByOtherDevices) { m_fuelConsumedByOtherDevices = fuelConsumedByOtherDevices; }

    /// <summary>
    /// Remaining fuel on board based on Engine Room log entries, measured in metric tonnes.
    /// </summary>
    double getFuelRemainingOnBoard() const { return m_fuelRemainingOnBoard; }
    void setFuelRemainingOnBoard(double fuelRemainingOnBoard) { m_fuelRemainingOnBoard = fuelRemainingOnBoard; }

    /// <summary>
    /// Amount of sludge remaining onboard, measured in metric tonnes.
    /// </summary>
    double getSludgeRemainingOnBoard() const { return m_sludgeRemainingOnBoard; }
    void setSludgeRemainingOnBoard(double sludgeRemainingOnBoard) { m_sludgeRemainingOnBoard = sludgeRemainingOnBoard; }
};

} // namespace models
} // namespace svd
