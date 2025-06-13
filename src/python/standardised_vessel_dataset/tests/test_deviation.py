"""Tests for the DeviationFromPlanned model."""

from datetime import datetime, timedelta

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.deviation import DeviationFromPlanned


def test_valid_deviation_from_planned():
    """Test creating a valid DeviationFromPlanned instance."""
    now = datetime.now()
    started_time = now - timedelta(hours=2)
    stopped_time = now - timedelta(hours=1)

    data = {
        "reason": "Weather conditions",
        "latitude": 45.5,
        "longitude": -122.5,
        "ship_deviation_started_time": started_time,
        "ship_deviation_stopped_time": stopped_time,
    }

    info = DeviationFromPlanned(**data)
    assert info.reason == "Weather conditions"
    assert info.latitude == 45.5
    assert info.longitude == -122.5
    assert info.ship_deviation_started_time == started_time
    assert info.ship_deviation_stopped_time == stopped_time


def test_invalid_latitude():
    """Test validation of latitude values."""
    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(latitude=91.0)
    assert "Latitude must be between -90 and 90 degrees" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(latitude=-91.0)
    assert "Latitude must be between -90 and 90 degrees" in str(exc_info.value)


def test_invalid_longitude():
    """Test validation of longitude values."""
    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(longitude=181.0)
    assert "Longitude must be between -180 and 180 degrees" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(longitude=-181.0)
    assert "Longitude must be between -180 and 180 degrees" in str(exc_info.value)


def test_invalid_deviation_times():
    """Test validation of deviation times."""
    now = datetime.now()
    future_time = now + timedelta(days=1)

    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(ship_deviation_started_time=future_time)
    assert "Deviation time cannot be in the future" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(ship_deviation_stopped_time=future_time)
    assert "Deviation time cannot be in the future" in str(exc_info.value)

    # Test that stopped time must be after started time
    started_time = now
    stopped_time = now - timedelta(hours=1)

    with pytest.raises(ValidationError) as exc_info:
        DeviationFromPlanned(
            ship_deviation_started_time=started_time,
            ship_deviation_stopped_time=stopped_time,
        )
    assert "Deviation stopped time must be after started time" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = DeviationFromPlanned()
    assert info.reason is None
    assert info.latitude is None
    assert info.longitude is None
    assert info.ship_deviation_started_time is None
    assert info.ship_deviation_stopped_time is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "reason": "Weather conditions",
        "latitude": 45.5,
    }

    info = DeviationFromPlanned(**data)
    assert info.reason == "Weather conditions"
    assert info.latitude == 45.5
    assert info.longitude is None
    assert info.ship_deviation_started_time is None
    assert info.ship_deviation_stopped_time is None 