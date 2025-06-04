#pragma once

#include <chrono>

namespace svd::models {

/**
 * @brief Represents arrival time information in the SVD
 */
class ArrivalTimes 
{
public:
    ArrivalTimes() = default;
    ~ArrivalTimes() = default;
    
    // Copy and move constructors/assignment operators
    ArrivalTimes(const ArrivalTimes&) = default;
    ArrivalTimes& operator=(const ArrivalTimes&) = default;
    ArrivalTimes(ArrivalTimes&&) = default;
    ArrivalTimes& operator=(ArrivalTimes&&) = default;    // Getters
    const std::chrono::system_clock::time_point& getEstimatedTimeOfArrival() const { return m_estimatedTimeOfArrival; }
    const std::chrono::system_clock::time_point& getActualTimeOfArrival() const { return m_actualTimeOfArrival; }
    const std::chrono::system_clock::time_point& getPlannedTimeOfDeparture() const { return m_plannedTimeOfDeparture; }
    const std::chrono::system_clock::time_point& getActualTimeOfDeparture() const { return m_actualTimeOfDeparture; }
    
    // Setters
    void setEstimatedTimeOfArrival(const std::chrono::system_clock::time_point& eta) { m_estimatedTimeOfArrival = eta; }
    void setActualTimeOfArrival(const std::chrono::system_clock::time_point& ata) { m_actualTimeOfArrival = ata; }
    void setPlannedTimeOfDeparture(const std::chrono::system_clock::time_point& ptd) { m_plannedTimeOfDeparture = ptd; }
    void setActualTimeOfDeparture(const std::chrono::system_clock::time_point& atd) { m_actualTimeOfDeparture = atd; }

private:
    std::chrono::system_clock::time_point m_estimatedTimeOfArrival;
    std::chrono::system_clock::time_point m_actualTimeOfArrival;
    std::chrono::system_clock::time_point m_plannedTimeOfDeparture;
    std::chrono::system_clock::time_point m_actualTimeOfDeparture;
};

} // namespace svd::models
