#include "svd/models/standardised_vessel_dataset.hpp"

namespace svd::models {

StandardisedVesselDataset::StandardisedVesselDataset() = default;



StandardisedVesselDataset::StandardisedVesselDataset(const StandardisedVesselDataset& other)
    : m_general(other.m_general),
      m_portAndRoute(other.m_portAndRoute),
      m_arrivalTimes(other.m_arrivalTimes),
      m_weather(other.m_weather),
      m_cargo(other.m_cargo),
      m_fuelAndBunker(other.m_fuelAndBunker),
      m_emissions(other.m_emissions),
      m_speedAndDistance(other.m_speedAndDistance),
      m_electricityConsumption(other.m_electricityConsumption),
      m_freshWater(other.m_freshWater),
      m_cylinderLubeOil(other.m_cylinderLubeOil),
      m_deviationFromPlanned(other.m_deviationFromPlanned)
{
}

StandardisedVesselDataset& StandardisedVesselDataset::operator=(const StandardisedVesselDataset& other) 
{
    if (this != &other) 
    {
        m_general = other.m_general;
        m_portAndRoute = other.m_portAndRoute;
        m_arrivalTimes = other.m_arrivalTimes;
        m_weather = other.m_weather;
        m_cargo = other.m_cargo;
        m_fuelAndBunker = other.m_fuelAndBunker;
        m_emissions = other.m_emissions;
        m_speedAndDistance = other.m_speedAndDistance;
        m_electricityConsumption = other.m_electricityConsumption;
        m_freshWater = other.m_freshWater;
        m_cylinderLubeOil = other.m_cylinderLubeOil;
        m_deviationFromPlanned = other.m_deviationFromPlanned;
    }
    return *this;
}

StandardisedVesselDataset::StandardisedVesselDataset(StandardisedVesselDataset&& other) noexcept
    : m_general(std::move(other.m_general)),
      m_portAndRoute(std::move(other.m_portAndRoute)),
      m_arrivalTimes(std::move(other.m_arrivalTimes)),
      m_weather(std::move(other.m_weather)),
      m_cargo(std::move(other.m_cargo)),
      m_fuelAndBunker(std::move(other.m_fuelAndBunker)),
      m_emissions(std::move(other.m_emissions)),
      m_speedAndDistance(std::move(other.m_speedAndDistance)),
      m_electricityConsumption(std::move(other.m_electricityConsumption)),
      m_freshWater(std::move(other.m_freshWater)),
      m_cylinderLubeOil(std::move(other.m_cylinderLubeOil)),
      m_deviationFromPlanned(std::move(other.m_deviationFromPlanned))
{
}

StandardisedVesselDataset& StandardisedVesselDataset::operator=(StandardisedVesselDataset&& other) noexcept {
    if (this != &other) {
        m_general = std::move(other.m_general);
        m_portAndRoute = std::move(other.m_portAndRoute);
        m_arrivalTimes = std::move(other.m_arrivalTimes);
        m_weather = std::move(other.m_weather);
        m_cargo = std::move(other.m_cargo);
        m_fuelAndBunker = std::move(other.m_fuelAndBunker);
        m_emissions = std::move(other.m_emissions);
        m_speedAndDistance = std::move(other.m_speedAndDistance);
        m_electricityConsumption = std::move(other.m_electricityConsumption);
        m_freshWater = std::move(other.m_freshWater);
        m_cylinderLubeOil = std::move(other.m_cylinderLubeOil);
        m_deviationFromPlanned = std::move(other.m_deviationFromPlanned);
    }
    return *this;
}

} // namespace svd::models
