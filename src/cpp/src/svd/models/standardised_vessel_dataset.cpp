#include "svd/models/standardised_vessel_dataset.hpp"

namespace svd::models {

StandardisedVesselDataset::StandardisedVesselDataset() = default;

StandardisedVesselDataset::~StandardisedVesselDataset() = default;

StandardisedVesselDataset::StandardisedVesselDataset(const StandardisedVesselDataset& other)
    : m_general(other.m_general),
      m_portAndRoute(other.m_portAndRoute),
      m_arrivalTimes(other.m_arrivalTimes),
      m_weather(other.m_weather) 
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
    }
    return *this;
}

StandardisedVesselDataset::StandardisedVesselDataset(StandardisedVesselDataset&& other) noexcept
    : m_general(std::move(other.m_general)),
      m_portAndRoute(std::move(other.m_portAndRoute)),
      m_arrivalTimes(std::move(other.m_arrivalTimes)),
      m_weather(std::move(other.m_weather)) 
{
}

StandardisedVesselDataset& StandardisedVesselDataset::operator=(StandardisedVesselDataset&& other) noexcept {
    if (this != &other) {
        general_ = std::move(other.general_);
        port_and_route_ = std::move(other.port_and_route_);
        arrival_times_ = std::move(other.arrival_times_);
        weather_ = std::move(other.weather_);
    }
    return *this;
}

} // namespace svd::models
