#pragma once

#include "../ivalidator.hpp"

// Forward declarations
namespace svd::models {
    class StandardisedVesselDataset;
    class GeneralInformation;
    class PortInformation;
    class ArrivalTimes;
    class WeatherInformation;
}

namespace svd::validators {

/**
 * @brief Validator for StandardisedVesselDataset
 */
class StandardisedVesselDatasetValidator : public svd::IValidator<svd::models::StandardisedVesselDataset>
{
public:
    StandardisedVesselDatasetValidator() = default;
    ~StandardisedVesselDatasetValidator() override = default;

    // Delete copy constructor and assignment operator
    StandardisedVesselDatasetValidator(const StandardisedVesselDatasetValidator&) = delete;
    StandardisedVesselDatasetValidator& operator=(const StandardisedVesselDatasetValidator&) = delete;
    
    // Allow move construction and assignment
    StandardisedVesselDatasetValidator(StandardisedVesselDatasetValidator&&) = default;
    StandardisedVesselDatasetValidator& operator=(StandardisedVesselDatasetValidator&&) = default;

    // IValidator interface implementation
    svd::ValidationResult validate(const svd::models::StandardisedVesselDataset& data) const override;
    std::vector<svd::ValidationError> getErrors() const override;
    bool isValid(const svd::models::StandardisedVesselDataset& data) const override;

private:
    svd::ValidationResult validateGeneral(const svd::models::GeneralInformation& general) const;
    svd::ValidationResult validatePortInformation(const svd::models::PortInformation& portInfo) const;
    svd::ValidationResult validateArrivalTimes(const svd::models::ArrivalTimes& arrivalTimes) const;
    svd::ValidationResult validateWeatherInformation(const svd::models::WeatherInformation& weather) const;
    
    mutable std::vector<svd::ValidationError> m_lastErrors;
};

} // namespace svd::validators
