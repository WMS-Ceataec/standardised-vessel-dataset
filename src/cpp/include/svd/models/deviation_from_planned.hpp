#pragma once

#include <string>
#include <chrono>

namespace svd {
namespace models {

/// <summary>
/// Represent the "Deviation From Planned" section of SVD
/// </summary>
class DeviationFromPlanned
{
private:
    std::string m_reason;
    double m_latitude;
    double m_longitude;
    std::chrono::system_clock::time_point m_shipDeviationStartedTime;
    std::chrono::system_clock::time_point m_shipDeviationStoppedTime;

public:
    DeviationFromPlanned() = default;

    /// <summary>
    /// Description of why the ship has deviated from the planned voyage.
    /// </summary>
    const std::string& getReason() const { return m_reason; }
    void setReason(const std::string& reason) { m_reason = reason; }

    /// <summary>
    /// Latitude (geographical coordinate) of the location of the ship at the time of deviation.
    /// </summary>
    double getLatitude() const { return m_latitude; }
    void setLatitude(double latitude) { m_latitude = latitude; }

    /// <summary>
    /// Longitude (geographical coordinate) of the location of the ship at the time of deviation.
    /// </summary>
    double getLongitude() const { return m_longitude; }
    void setLongitude(double longitude) { m_longitude = longitude; }

    /// <summary>
    /// Date and time when the ship started its deviation from the planned voyage.
    /// </summary>
    const std::chrono::system_clock::time_point& getShipDeviationStartedTime() const { return m_shipDeviationStartedTime; }
    void setShipDeviationStartedTime(const std::chrono::system_clock::time_point& shipDeviationStartedTime) { m_shipDeviationStartedTime = shipDeviationStartedTime; }

    /// <summary>
    /// Date and time when the ship stopped its deviation from the planned voyage.
    /// </summary>
    const std::chrono::system_clock::time_point& getShipDeviationStoppedTime() const { return m_shipDeviationStoppedTime; }
    void setShipDeviationStoppedTime(const std::chrono::system_clock::time_point& shipDeviationStoppedTime) { m_shipDeviationStoppedTime = shipDeviationStoppedTime; }
};

} // namespace models
} // namespace svd
