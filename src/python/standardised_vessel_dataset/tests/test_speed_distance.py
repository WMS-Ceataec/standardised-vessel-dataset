"""Tests for the SpeedAndDistance model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.speed_distance import SpeedAndDistance


def test_valid_speed_distance():
    """Test creating a valid SpeedAndDistance instance."""
    data = {
        "distance_through_water": 100.0,
        "distance_over_ground": 98.5,
        "distance_sailed_in_ice": 0.0,
        "distance_to_next_port": 250.0,
        "distance_to_next_waypoint": 50.0,
        "total_distance_on_sea_passage": 1000.0,
        "distance_excluded": 0.0,
        "speed_over_ground": 12.5,
        "speed_through_water": 13.0,
        "speed_propeller": 90.0,
        "speed_projected": 12.0,
        "speed_order": 12.0,
        "slip": 0.5,
        "course_over_ground": 45.0,
        "ship_true_heading": 45.0,
        "ship_draught": "12.5",
        "draught_forward": 12.5,
        "draught_aft": 12.5,
        "ship_actual_deadweight_tonnage": 50000.0,
        "ship_maximum_deadweight": 60000.0,
        "laden_indicator": True,
        "total_ballast_water_onboard": 5000.0,
    }

    info = SpeedAndDistance(**data)
    assert info.distance_through_water == 100.0
    assert info.speed_over_ground == 12.5
    assert info.laden_indicator is True


def test_invalid_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(distance_through_water=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(speed_over_ground=-5.0)
    assert "Value must be non-negative" in str(exc_info.value)


def test_invalid_angles():
    """Test validation of angle values."""
    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(course_over_ground=361.0)
    assert "Angle must be between 0 and 360 degrees" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(ship_true_heading=-1.0)
    assert "Angle must be between 0 and 360 degrees" in str(exc_info.value)


def test_invalid_draught():
    """Test validation of draught values."""
    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(draught_forward=0.0)
    assert "Draught must be positive" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(draught_aft=-1.0)
    assert "Draught must be positive" in str(exc_info.value)


def test_invalid_deadweight():
    """Test validation of deadweight values."""
    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(ship_actual_deadweight_tonnage=0.0)
    assert "Deadweight must be positive" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        SpeedAndDistance(ship_maximum_deadweight=-1000.0)
    assert "Deadweight must be positive" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = SpeedAndDistance()
    assert info.distance_through_water is None
    assert info.speed_over_ground is None
    assert info.laden_indicator is None 