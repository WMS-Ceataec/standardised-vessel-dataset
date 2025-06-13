"""Tests for the exporters."""

import json
from datetime import datetime

import pandas as pd
import pytest

from standardised_vessel_dataset.exporters.csv import CsvExporter
from standardised_vessel_dataset.exporters.json import JsonExporter
from standardised_vessel_dataset.models.dataset import StandardizedVesselDataset


@pytest.fixture
def sample_dataset():
    """Create a sample dataset for testing."""
    return StandardizedVesselDataset(
        vessel_imo="1234567",
        vessel_name="Test Vessel",
        vessel_type="Container Ship",
        reporting_period_start=datetime.now(),
        reporting_period_end=datetime.now(),
    )


@pytest.mark.asyncio
async def test_csv_exporter(sample_dataset):
    """Test CSV exporter."""
    exporter = CsvExporter()
    result = await exporter.export(sample_dataset)

    # Check content type and filename
    assert result.content_type == "text/csv"
    assert result.filename.startswith("svd_1234567_")
    assert result.filename.endswith(".csv")

    # Check CSV content
    df = pd.read_csv(pd.io.common.BytesIO(result.content))
    assert len(df) == 1
    assert df["vessel_imo"].iloc[0] == "1234567"
    assert df["vessel_name"].iloc[0] == "Test Vessel"
    assert df["vessel_type"].iloc[0] == "Container Ship"


@pytest.mark.asyncio
async def test_json_exporter(sample_dataset):
    """Test JSON exporter."""
    exporter = JsonExporter()
    result = await exporter.export(sample_dataset)

    # Check content type and filename
    assert result.content_type == "application/json"
    assert result.filename.startswith("svd_1234567_")
    assert result.filename.endswith(".json")

    # Check JSON content
    data = json.loads(result.content.decode("utf-8"))
    assert data["vessel_imo"] == "1234567"
    assert data["vessel_name"] == "Test Vessel"
    assert data["vessel_type"] == "Container Ship"


@pytest.mark.asyncio
async def test_invalid_dataset():
    """Test exporting invalid dataset."""
    # Create invalid dataset
    dataset = StandardizedVesselDataset(
        vessel_imo="123456",  # Invalid IMO
        vessel_name="",  # Invalid name
        vessel_type="Container Ship",  # Required field
        reporting_period_start=datetime.now(),
        reporting_period_end=datetime.now(),
    )

    # Test CSV exporter
    exporter = CsvExporter()
    with pytest.raises(ValueError):
        await exporter.export(dataset)

    # Test JSON exporter
    exporter = JsonExporter()
    with pytest.raises(ValueError):
        await exporter.export(dataset) 