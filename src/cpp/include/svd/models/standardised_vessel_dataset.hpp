#pragma once

#include "general_information.hpp"
#include "port_information.hpp"
#include "arrival_times.hpp"
#include "weather_information.hpp"
#include "cargo_information.hpp"
#include "fuel_and_bunker_information.hpp"
#include "emissions.hpp"
#include "speed_and_distance.hpp"
#include "electricity_consumption.hpp"
#include "fresh_water.hpp"
#include "cylinder_lube_oil_information.hpp"
#include "deviation_from_planned.hpp"
#include <memory>

namespace svd::models {

/**
 * @brief Represents the Standardised Vessel Dataset (SVD)
 * 
 * See more: https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/
 */
class StandardisedVesselDataset 
{
public:
    StandardisedVesselDataset();
    ~StandardisedVesselDataset();
    
    // Copy and move constructors/assignment operators
    StandardisedVesselDataset(const StandardisedVesselDataset&);
    StandardisedVesselDataset& operator=(const StandardisedVesselDataset&);
    StandardisedVesselDataset(StandardisedVesselDataset&&) noexcept;
    StandardisedVesselDataset& operator=(StandardisedVesselDataset&&) noexcept;    // Getters
    const GeneralInformation& getGeneral() const { return m_general; }
    const PortInformation& getPortAndRoute() const { return m_portAndRoute; }
    const ArrivalTimes& getArrivalTimes() const { return m_arrivalTimes; }
    const WeatherInformation& getWeather() const { return m_weather; }
    const CargoInformation& getCargo() const { return m_cargo; }
    const FuelAndBunkerInformation& getFuelAndBunker() const { return m_fuelAndBunker; }
    const Emissions& getEmissions() const { return m_emissions; }
    const SpeedAndDistance& getSpeedAndDistance() const { return m_speedAndDistance; }
    const ElectricityConsumption& getElectricityConsumption() const { return m_electricityConsumption; }
    const FreshWater& getFreshWater() const { return m_freshWater; }
    const CylinderLubeOilInformation& getCylinderLubeOil() const { return m_cylinderLubeOil; }
    const DeviationFromPlanned& getDeviationFromPlanned() const { return m_deviationFromPlanned; }
    
    GeneralInformation& getGeneral() { return m_general; }
    PortInformation& getPortAndRoute() { return m_portAndRoute; }
    ArrivalTimes& getArrivalTimes() { return m_arrivalTimes; }
    WeatherInformation& getWeather() { return m_weather; }
    CargoInformation& getCargo() { return m_cargo; }
    FuelAndBunkerInformation& getFuelAndBunker() { return m_fuelAndBunker; }
    Emissions& getEmissions() { return m_emissions; }
    SpeedAndDistance& getSpeedAndDistance() { return m_speedAndDistance; }
    ElectricityConsumption& getElectricityConsumption() { return m_electricityConsumption; }
    FreshWater& getFreshWater() { return m_freshWater; }
    CylinderLubeOilInformation& getCylinderLubeOil() { return m_cylinderLubeOil; }
    DeviationFromPlanned& getDeviationFromPlanned() { return m_deviationFromPlanned; }
    
    // Setters
    void setGeneral(const GeneralInformation& general) { m_general = general; }
    void setPortAndRoute(const PortInformation& portAndRoute) { m_portAndRoute = portAndRoute; }
    void setArrivalTimes(const ArrivalTimes& arrivalTimes) { m_arrivalTimes = arrivalTimes; }
    void setWeather(const WeatherInformation& weather) { m_weather = weather; }
    void setCargo(const CargoInformation& cargo) { m_cargo = cargo; }
    void setFuelAndBunker(const FuelAndBunkerInformation& fuelAndBunker) { m_fuelAndBunker = fuelAndBunker; }
    void setEmissions(const Emissions& emissions) { m_emissions = emissions; }
    void setSpeedAndDistance(const SpeedAndDistance& speedAndDistance) { m_speedAndDistance = speedAndDistance; }
    void setElectricityConsumption(const ElectricityConsumption& electricityConsumption) { m_electricityConsumption = electricityConsumption; }
    void setFreshWater(const FreshWater& freshWater) { m_freshWater = freshWater; }
    void setCylinderLubeOil(const CylinderLubeOilInformation& cylinderLubeOil) { m_cylinderLubeOil = cylinderLubeOil; }
    void setDeviationFromPlanned(const DeviationFromPlanned& deviationFromPlanned) { m_deviationFromPlanned = deviationFromPlanned; }

private:
    GeneralInformation m_general;
    PortInformation m_portAndRoute;
    ArrivalTimes m_arrivalTimes;
    WeatherInformation m_weather;
    CargoInformation m_cargo;
    FuelAndBunkerInformation m_fuelAndBunker;
    Emissions m_emissions;
    SpeedAndDistance m_speedAndDistance;
    ElectricityConsumption m_electricityConsumption;
    FreshWater m_freshWater;
    CylinderLubeOilInformation m_cylinderLubeOil;
    DeviationFromPlanned m_deviationFromPlanned;
};

} // namespace svd::models
