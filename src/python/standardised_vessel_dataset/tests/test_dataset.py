"""Tests for the dataset model."""

from datetime import datetime

import pandas as pd
import pytest
from pydantic import ValidationError

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


def test_valid_dataset(sample_dataset):
    """Test creating a valid dataset."""
    assert sample_dataset.vessel_imo == "1234567"
    assert sample_dataset.vessel_name == "Test Vessel"
    assert sample_dataset.vessel_type == "Container Ship"
    assert isinstance(sample_dataset.reporting_period_start, datetime)
    assert isinstance(sample_dataset.reporting_period_end, datetime)


def test_invalid_imo():
    """Test creating a dataset with invalid IMO."""
    with pytest.raises(ValidationError):
        StandardizedVesselDataset(
            vessel_imo="123456",  # Invalid IMO
            vessel_name="Test Vessel",
            vessel_type="Container Ship",
            reporting_period_start=datetime.now(),
            reporting_period_end=datetime.now(),
        )


def test_invalid_name():
    """Test creating a dataset with invalid name."""
    with pytest.raises(ValidationError):
        StandardizedVesselDataset(
            vessel_imo="1234567",
            vessel_name="",  # Invalid name
            vessel_type="Container Ship",
            reporting_period_start=datetime.now(),
            reporting_period_end=datetime.now(),
        )


def test_invalid_period():
    """Test creating a dataset with invalid reporting period."""
    with pytest.raises(ValidationError):
        StandardizedVesselDataset(
            vessel_imo="1234567",
            vessel_name="Test Vessel",
            vessel_type="Container Ship",
            reporting_period_start=datetime.now(),
            reporting_period_end=datetime.now().replace(year=2020),  # End before start
        )


def test_to_dataframe(sample_dataset):
    """Test converting dataset to DataFrame."""
    df = sample_dataset.to_dataframe()
    assert isinstance(df, pd.DataFrame)
    assert len(df) == 1
    assert df["vessel_imo"].iloc[0] == "1234567"
    assert df["vessel_name"].iloc[0] == "Test Vessel"
    assert df["vessel_type"].iloc[0] == "Container Ship"


def test_to_csv(sample_dataset, tmp_path):
    """Test exporting dataset to CSV."""
    csv_path = tmp_path / "test.csv"
    sample_dataset.to_csv(csv_path)
    assert csv_path.exists()
    
    # Read back and verify
    df = pd.read_csv(csv_path)
    assert len(df) == 1
    assert df["vessel_imo"].iloc[0] == "1234567"
    assert df["vessel_name"].iloc[0] == "Test Vessel"
    assert df["vessel_type"].iloc[0] == "Container Ship"


def test_from_csv(tmp_path):
    """Test creating dataset from CSV."""
    # Create test CSV
    df = pd.DataFrame({
        "vessel_imo": ["1234567"],
        "vessel_name": ["Test Vessel"],
        "vessel_type": ["Container Ship"],
        "reporting_period_start": [datetime.now().isoformat()],
        "reporting_period_end": [datetime.now().isoformat()],
    })
    csv_path = tmp_path / "test.csv"
    df.to_csv(csv_path, index=False)
    
    # Read back and verify
    dataset = StandardizedVesselDataset.from_csv(csv_path)
    assert dataset.vessel_imo == "1234567"
    assert dataset.vessel_name == "Test Vessel"
    assert dataset.vessel_type == "Container Ship"
    assert isinstance(dataset.reporting_period_start, datetime)
    assert isinstance(dataset.reporting_period_end, datetime) 