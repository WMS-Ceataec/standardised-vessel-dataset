#pragma once

#include "errors/validation_error.hpp"
#include "../models/standardised_vessel_dataset.hpp"
#include <future>

namespace svd::validators {

/**
 * @brief Interface for validators
 */
class IValidator {
public:
    virtual ~IValidator() = default;

    /**
     * @brief Validates the given SVD object
     * @param svd The StandardisedVesselDataset to validate
     * @return ValidationResult containing any validation errors
     */
    virtual std::future<ValidationResult> validateAsync(const models::StandardisedVesselDataset& svd) = 0;
};

} // namespace svd::validators
