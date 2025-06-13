"""JSON exporter for the Standardised Vessel Dataset."""

import json
from datetime import datetime

from standardised_vessel_dataset.exporters.base import BaseExporter, ExportResult
from standardised_vessel_dataset.models.dataset import StandardizedVesselDataset


class JsonExporter(BaseExporter):
    """JSON exporter for the Standardised Vessel Dataset."""

    async def _export(self, dataset: StandardizedVesselDataset) -> ExportResult:
        """Export the dataset to JSON format.

        Args:
            dataset: The dataset to export

        Returns:
            An ExportResult containing the exported data
        """
        # Convert dataset to JSON
        content = dataset.model_dump_json(indent=2)

        # Generate filename
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"svd_{dataset.vessel_imo}_{timestamp}.json"

        return ExportResult(
            content=content.encode("utf-8"),
            content_type="application/json",
            filename=filename,
        ) 