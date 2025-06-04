#pragma once

#include <string>

namespace svd::models {

/**
 * @brief Represents weather information in the SVD
 */
class WeatherInformation 
{
public:
    WeatherInformation() = default;
    ~WeatherInformation() = default;
    
    // Copy and move constructors/assignment operators
    WeatherInformation(const WeatherInformation&) = default;
    WeatherInformation& operator=(const WeatherInformation&) = default;
    WeatherInformation(WeatherInformation&&) = default;
    WeatherInformation& operator=(WeatherInformation&&) = default;    // Getters
    double getWindSpeed() const { return m_windSpeed; }
    double getWindDirection() const { return m_windDirection; }
    double getSeaState() const { return m_seaState; }
    double getSwellHeight() const { return m_swellHeight; }
    double getSwellDirection() const { return m_swellDirection; }
    double getAirTemperature() const { return m_airTemperature; }
    double getSeaWaterTemperature() const { return m_seaWaterTemperature; }
    double getBarometricPressure() const { return m_barometricPressure; }
    const std::string& getWeatherDescription() const { return m_weatherDescription; }

    // Setters
    void setWindSpeed(double windSpeed) { m_windSpeed = windSpeed; }
    void setWindDirection(double windDirection) { m_windDirection = windDirection; }
    void setSeaState(double seaState) { m_seaState = seaState; }
    void setSwellHeight(double swellHeight) { m_swellHeight = swellHeight; }
    void setSwellDirection(double swellDirection) { m_swellDirection = swellDirection; }
    void setAirTemperature(double airTemperature) { m_airTemperature = airTemperature; }
    void setSeaWaterTemperature(double seaWaterTemperature) { m_seaWaterTemperature = seaWaterTemperature; }
    void setBarometricPressure(double barometricPressure) { m_barometricPressure = barometricPressure; }
    void setWeatherDescription(const std::string& weatherDescription) { m_weatherDescription = weatherDescription; }

private:
    double m_windSpeed = 0.0;
    double m_windDirection = 0.0;
    double m_seaState = 0.0;
    double m_swellHeight = 0.0;
    double m_swellDirection = 0.0;
    double m_airTemperature = 0.0;
    double m_seaWaterTemperature = 0.0;
    double m_barometricPressure = 0.0;
    std::string m_weatherDescription;
};

} // namespace svd::models
