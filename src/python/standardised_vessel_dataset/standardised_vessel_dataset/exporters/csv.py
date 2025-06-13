"""CSV exporter for the Standardised Vessel Dataset."""

import io
from datetime import datetime

import pandas as pd

from standardised_vessel_dataset.exporters.base import BaseExporter, ExportResult
from standardised_vessel_dataset.models.dataset import StandardizedVesselDataset


class CsvExporter(BaseExporter):
    """CSV exporter for the Standardised Vessel Dataset."""

    async def _export(self, dataset: StandardizedVesselDataset) -> ExportResult:
        """Export the dataset to CSV format.

        Args:
            dataset: The dataset to export

        Returns:
            An ExportResult containing the exported data
        """
        # Convert dataset to DataFrame
        df = dataset.to_dataframe()

        # Create CSV buffer
        buffer = io.BytesIO()
        df.to_csv(buffer, index=False)

        # Generate filename
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"svd_{dataset.vessel_imo}_{timestamp}.csv"

        return ExportResult(
            content=buffer.getvalue(),
            content_type="text/csv",
            filename=filename,
        ) 