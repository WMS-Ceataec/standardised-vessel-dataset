"""Dataset validator for the Standardised Vessel Dataset."""

from typing import Any, Dict

from pydantic import ValidationError

from ..models.dataset import StandardizedVesselDataset
from .base import BaseValidator


class DatasetValidator(BaseValidator):
    """Validator for the Standardised Vessel Dataset."""

    def _validate(self, data: Dict[str, Any]) -> None:
        """Validate the dataset.

        Args:
            data: The dataset to validate

        Raises:
            ValidationError: If validation fails
        """
        # First validate the entire dataset structure
        try:
            dataset = StandardizedVesselDataset(**data)
        except ValidationError as e:
            raise ValidationError(e.errors())

        # Then validate the general information if present
        if dataset.general_information:
            # TODO: Add validation for general information
            pass

        # TODO: Add validation for other sections as they are implemented 