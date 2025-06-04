#pragma once

#include <string>
#include <vector>

namespace svd::validators {

/**
 * @brief Represents a validation error
 */
class ValidationError {
public:
    ValidationError(std::string property_name, std::string error_message);
    ~ValidationError() = default;
    
    // Copy and move constructors/assignment operators
    ValidationError(const ValidationError&) = default;
    ValidationError& operator=(const ValidationError&) = default;
    ValidationError(ValidationError&&) = default;
    ValidationError& operator=(ValidationError&&) = default;

    // Getters
    const std::string& getPropertyName() const { return property_name_; }
    const std::string& getErrorMessage() const { return error_message_; }

private:
    std::string property_name_;
    std::string error_message_;
};

/**
 * @brief Represents validation result containing errors if any
 */
class ValidationResult {
public:
    ValidationResult() = default;
    explicit ValidationResult(std::vector<ValidationError> errors);
    ~ValidationResult() = default;
    
    // Copy and move constructors/assignment operators
    ValidationResult(const ValidationResult&) = default;
    ValidationResult& operator=(const ValidationResult&) = default;
    ValidationResult(ValidationResult&&) = default;
    ValidationResult& operator=(ValidationResult&&) = default;

    // Methods
    bool isValid() const { return errors_.empty(); }
    const std::vector<ValidationError>& getErrors() const { return errors_; }
    void addError(const ValidationError& error) { errors_.push_back(error); }
    void addError(ValidationError&& error) { errors_.push_back(std::move(error)); }

private:
    std::vector<ValidationError> errors_;
};

} // namespace svd::validators
