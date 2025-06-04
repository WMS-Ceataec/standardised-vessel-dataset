#pragma once

#include <string>
#include <chrono>

namespace svd::models {

/**
 * @brief Represents port and route information in the SVD
 */
class PortInformation 
{
public:
    PortInformation() = default;
    ~PortInformation() = default;
    
    // Copy and move constructors/assignment operators
    PortInformation(const PortInformation&) = default;
    PortInformation& operator=(const PortInformation&) = default;
    PortInformation(PortInformation&&) = default;
    PortInformation& operator=(PortInformation&&) = default;    // Getters
    const std::string& getDeparturePortCode() const { return m_departurePortCode; }
    const std::string& getDeparturePortName() const { return m_departurePortName; }
    const std::string& getArrivalPortCode() const { return m_arrivalPortCode; }
    const std::string& getArrivalPortName() const { return m_arrivalPortName; }
    const std::string& getRouteCode() const { return m_routeCode; }
    const std::string& getRouteDescription() const { return m_routeDescription; }
    double getPlannedDistance() const { return m_plannedDistance; }
      // Setters
    void setDeparturePortCode(const std::string& departurePortCode) { m_departurePortCode = departurePortCode; }
    void setDeparturePortName(const std::string& departurePortName) { m_departurePortName = departurePortName; }
    void setArrivalPortCode(const std::string& arrivalPortCode) { m_arrivalPortCode = arrivalPortCode; }
    void setArrivalPortName(const std::string& arrivalPortName) { m_arrivalPortName = arrivalPortName; }
    void setRouteCode(const std::string& routeCode) { m_routeCode = routeCode; }
    void setRouteDescription(const std::string& routeDescription) { m_routeDescription = routeDescription; }
    void setPlannedDistance(double plannedDistance) { m_plannedDistance = plannedDistance; }

private:
    std::string m_departurePortCode;
    std::string m_departurePortName;
    std::string m_arrivalPortCode;
    std::string m_arrivalPortName;
    std::string m_routeCode;
    std::string m_routeDescription;
    double m_plannedDistance = 0.0;
};

} // namespace svd::models
