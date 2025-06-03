#include "svd/validators/exceptions/validation_exception.hpp"
#include <sstream>

namespace svd::validators {

ValidationException::ValidationException(const std::vector<ValidationError>& errors)
    : std::runtime_error(createMessage(errors)), errors_(errors) {
}

ValidationException::ValidationException(std::vector<ValidationError>&& errors)
    : std::runtime_error(createMessage(errors)), errors_(std::move(errors)) {
}

std::string ValidationException::createMessage(const std::vector<ValidationError>& errors) {
    std::ostringstream oss;
    oss << "Validation failed with " << errors.size() << " error(s):";
    
    for (const auto& error : errors) {
        oss << "\n  - " << error.getPropertyName() << ": " << error.getErrorMessage();
    }
    
    return oss.str();
}

} // namespace svd::validators
