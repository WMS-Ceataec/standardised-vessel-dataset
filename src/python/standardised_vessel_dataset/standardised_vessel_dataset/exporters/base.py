"""Base exporter for the Standardised Vessel Dataset."""

from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import Any, Dict, Optional

from standardised_vessel_dataset.models.dataset import StandardizedVesselDataset
from standardised_vessel_dataset.validators.dataset import DatasetValidator


@dataclass
class ExportResult:
    """Result of an export operation."""

    content: bytes
    content_type: str
    filename: str


class BaseExporter(ABC):
    """Base class for all exporters."""

    def __init__(self):
        """Initialize the exporter."""
        self.validator = DatasetValidator()

    async def export(self, dataset: StandardizedVesselDataset) -> ExportResult:
        """Export the dataset.

        Args:
            dataset: The dataset to export

        Returns:
            An ExportResult containing the exported data

        Raises:
            ValueError: If the dataset is invalid
        """
        # Validate the dataset
        result = self.validator.validate(dataset.model_dump())
        if not result.is_valid:
            raise ValueError(f"Invalid dataset: {', '.join(result.errors)}")

        # Export the dataset
        return await self._export(dataset)

    @abstractmethod
    async def _export(self, dataset: StandardizedVesselDataset) -> ExportResult:
        """Perform the actual export.

        Args:
            dataset: The dataset to export

        Returns:
            An ExportResult containing the exported data
        """
        raise NotImplementedError("Subclasses must implement _export") 