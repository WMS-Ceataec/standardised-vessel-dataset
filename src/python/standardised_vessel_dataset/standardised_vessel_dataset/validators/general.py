"""General information validator for the Standardised Vessel Dataset."""

from datetime import datetime
from typing import Any, Dict

from pydantic import ValidationError

from ..models.general import GeneralInformation
from .base import BaseValidator


class GeneralValidator(BaseValidator):
    """Validator for general vessel information."""

    def _validate(self, data: Dict[str, Any]) -> None:
        """Validate general vessel information.

        Args:
            data: The general information to validate

        Raises:
            ValidationError: If validation fails
        """
        # First validate the general information structure
        try:
            info = GeneralInformation(**data)
        except ValidationError as e:
            raise ValidationError(e.errors())

        # Then validate the IMO number
        if info.vessel_imo:
            if not info.vessel_imo.isdigit() or len(info.vessel_imo) != 7:
                raise ValidationError([{"loc": ["vessel_imo"], "msg": "IMO number must be 7 digits", "type": "value_error"}])

        # Validate vessel name
        if info.vessel_name:
            if not info.vessel_name.strip():
                raise ValidationError([{"loc": ["vessel_name"], "msg": "Vessel name cannot be empty", "type": "value_error"}])

        # Validate reporting period
        if info.reporting_period_start and info.reporting_period_end:
            if info.reporting_period_end <= info.reporting_period_start:
                raise ValidationError([{"loc": ["reporting_period"], "msg": "Reporting period end must be after start", "type": "value_error"}]) 