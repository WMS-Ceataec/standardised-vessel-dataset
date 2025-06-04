#include "svd/validators/errors/validation_error.hpp"

namespace svd::validators {

ValidationError::ValidationError(std::string property_name, std::string error_message)
    : property_name_(std::move(property_name)), error_message_(std::move(error_message)) {
}

ValidationResult::ValidationResult(std::vector<ValidationError> errors)
    : errors_(std::move(errors)) {
}

} // namespace svd::validators
