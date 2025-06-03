#include "../../../include/svd/validators/standardised_vessel_dataset_validator.hpp"
#include "../../../include/svd/models/standardised_vessel_dataset.hpp"
#include "../../../include/svd/models/general_information.hpp"
#include "../../../include/svd/models/port_information.hpp"
#include "../../../include/svd/models/arrival_times.hpp"
#include "../../../include/svd/models/weather_information.hpp"

namespace svd::validators {

svd::ValidationResult StandardisedVesselDatasetValidator::validate(const svd::models::StandardisedVesselDataset& data) const
{
    svd::ValidationResult result(true);
    m_lastErrors.clear();

    // Validate general information
    auto generalResult = validateGeneral(data.getGeneral());
    if (!generalResult.isValid) {
        result.isValid = false;
        result.errors.insert(result.errors.end(), generalResult.errors.begin(), generalResult.errors.end());
    }

    // Validate port information
    auto portResult = validatePortInformation(data.getPortAndRoute());
    if (!portResult.isValid) {
        result.isValid = false;
        result.errors.insert(result.errors.end(), portResult.errors.begin(), portResult.errors.end());
    }

    // Validate arrival times
    auto arrivalResult = validateArrivalTimes(data.getArrivalTimes());
    if (!arrivalResult.isValid) {
        result.isValid = false;
        result.errors.insert(result.errors.end(), arrivalResult.errors.begin(), arrivalResult.errors.end());
    }

    // Validate weather information
    auto weatherResult = validateWeatherInformation(data.getWeather());
    if (!weatherResult.isValid) {
        result.isValid = false;
        result.errors.insert(result.errors.end(), weatherResult.errors.begin(), weatherResult.errors.end());
    }    // Store errors for getErrors() method
    m_lastErrors = result.errors;

    return result;
}

std::vector<svd::ValidationError> StandardisedVesselDatasetValidator::getErrors() const
{
    return m_lastErrors;
}

bool StandardisedVesselDatasetValidator::isValid(const svd::models::StandardisedVesselDataset& data) const
{
    auto result = validate(data);
    return result.isValid;
}

svd::ValidationResult StandardisedVesselDatasetValidator::validateGeneral(const svd::models::GeneralInformation& general) const
{
    svd::ValidationResult result(true);

    // Validate ship name
    if (general.getShipName().empty()) {
        result.addError("general.shipName", "Ship name cannot be empty", svd::ValidationSeverity::Error);
    }

    // Validate IMO number
    if (general.getImo().empty()) {
        result.addError("general.imo", "IMO number cannot be empty", svd::ValidationSeverity::Error);
    } else if (general.getImo().length() != 7) {
        result.addError("general.imo", "IMO number must be 7 digits", svd::ValidationSeverity::Error);
    }

    // Validate call sign
    if (general.getCallSign().empty()) {
        result.addError("general.callSign", "Call sign cannot be empty", svd::ValidationSeverity::Warning);
    }

    return result;
}

svd::ValidationResult StandardisedVesselDatasetValidator::validatePortInformation(const svd::models::PortInformation& portInfo) const
{
    svd::ValidationResult result(true);

    // Check if departure port is provided
    if (portInfo.getDeparturePortCode().empty())
    {
        result.addError("portInformation.departurePortCode", "Departure port code cannot be empty", svd::ValidationSeverity::Error);
    }

    // Check if arrival port is provided 
    if (portInfo.getArrivalPortCode().empty())
    {
        result.addError("portInformation.arrivalPortCode", "Arrival port code cannot be empty", svd::ValidationSeverity::Error);
    }

    return result;
}

svd::ValidationResult StandardisedVesselDatasetValidator::validateArrivalTimes(const svd::models::ArrivalTimes& arrivalTimes) const
{
    svd::ValidationResult result(true);

    // For now, just validate that the class is well-formed
    // You can add specific time validation logic based on actual ArrivalTimes class properties
    
    return result;
}

svd::ValidationResult StandardisedVesselDatasetValidator::validateWeatherInformation(const svd::models::WeatherInformation& weather) const
{
    svd::ValidationResult result(true);

    // For now, just validate that the class is well-formed
    // You can add specific weather validation logic based on actual WeatherInformation class properties
    
    return result;
}

} // namespace svd::validators