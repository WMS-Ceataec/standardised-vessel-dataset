"""Base validator for the Standardised Vessel Dataset."""

from typing import Any, Dict, List, Optional
from pydantic import BaseModel, ValidationError


class ValidationResult:
    """Result of a validation operation."""

    def __init__(self, is_valid: bool, errors: Optional[List[str]] = None):
        """Initialize a validation result.

        Args:
            is_valid: Whether the validation passed
            errors: List of validation error messages
        """
        self.is_valid = is_valid
        self.errors = errors or []

    def __bool__(self) -> bool:
        """Return whether the validation passed."""
        return self.is_valid


class BaseValidator:
    """Base class for all validators."""

    def validate(self, data: Dict[str, Any]) -> ValidationResult:
        """Validate the given data.

        Args:
            data: The data to validate

        Returns:
            A ValidationResult indicating whether validation passed and any errors
        """
        try:
            self._validate(data)
            return ValidationResult(True)
        except ValidationError as e:
            return ValidationResult(False, [str(err) for err in e.errors()])

    def _validate(self, data: Dict[str, Any]) -> None:
        """Perform the actual validation.

        Args:
            data: The data to validate

        Raises:
            ValidationError: If validation fails
        """
        raise NotImplementedError("Subclasses must implement _validate") 