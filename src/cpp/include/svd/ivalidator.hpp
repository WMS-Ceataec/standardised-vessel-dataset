#pragma once

#include <vector>
#include <string>

namespace svd {
    // Forward declaration
    class StandardisedVesselDataset;

    /**
     * @brief Enumeration for validation error severity
     */
    enum class ValidationSeverity {
        Warning,
        Error,
        Critical
    };

    /**
     * @brief Structure representing a validation error
     */
    struct ValidationError {
        std::string field;
        std::string message;
        ValidationSeverity severity;

        ValidationError(const std::string& f, const std::string& msg, ValidationSeverity sev = ValidationSeverity::Error)
            : field(f), message(msg), severity(sev) {}
    };

    /**
     * @brief Structure representing validation result
     */
    struct ValidationResult {
        bool isValid;
        std::vector<ValidationError> errors;

        ValidationResult(bool valid = true) : isValid(valid) {}

        void addError(const ValidationError& error) {
            errors.push_back(error);
            isValid = false;
        }

        void addError(const std::string& field, const std::string& message, ValidationSeverity severity = ValidationSeverity::Error) {
            addError(ValidationError(field, message, severity));
        }
    };

    /**
     * @brief Template interface for data validators
     */
    template<typename T>
    class IValidator {
    public:
        virtual ~IValidator() = default;

        /**
         * @brief Validate the provided data
         * @param data The data to validate
         * @return ValidationResult containing validation status and errors
         */
        virtual ValidationResult validate(const T& data) const = 0;

        /**
         * @brief Get the last validation errors
         * @return Vector of validation errors
         */
        virtual std::vector<ValidationError> getErrors() const = 0;

        /**
         * @brief Check if the last validation was successful
         * @param data The data to validate
         * @return True if valid, false otherwise
         */
        virtual bool isValid(const T& data) const = 0;
    };

} // namespace svd