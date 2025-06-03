#pragma once

#include "../errors/validation_error.hpp"
#include <stdexcept>

namespace svd::validators {

/**
 * @brief Exception thrown when validation fails
 */
class ValidationException : public std::runtime_error {
public:
    explicit ValidationException(const std::vector<ValidationError>& errors);
    explicit ValidationException(std::vector<ValidationError>&& errors);
    ~ValidationException() override = default;

    // Getters
    const std::vector<ValidationError>& getErrors() const { return errors_; }

private:
    std::vector<ValidationError> errors_;
    
    static std::string createMessage(const std::vector<ValidationError>& errors);
};

} // namespace svd::validators
