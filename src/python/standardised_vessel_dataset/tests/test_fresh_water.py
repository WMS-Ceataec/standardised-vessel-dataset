"""Tests for the FreshWater model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.fresh_water import FreshWater


def test_valid_fresh_water():
    """Test creating a valid FreshWater instance."""
    data = {
        "fresh_water_bunkered": 100.0,
        "fresh_water_produced": 50.0,
        "fresh_water_consumed": 120.0,
        "fresh_water_remaining": 30.0,
        "technical_water_produced": 200.0,
        "technical_water_consumed": 150.0,
        "wash_water_consumed": 80.0,
    }

    info = FreshWater(**data)
    assert info.fresh_water_bunkered == 100.0
    assert info.fresh_water_produced == 50.0
    assert info.fresh_water_consumed == 120.0
    assert info.technical_water_produced == 200.0
    assert info.wash_water_consumed == 80.0


def test_invalid_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        FreshWater(fresh_water_bunkered=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        FreshWater(fresh_water_produced=-50.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        FreshWater(technical_water_consumed=-20.0)
    assert "Value must be non-negative" in str(exc_info.value)


def test_invalid_fresh_water_consumption():
    """Test validation of fresh water consumption."""
    # Test consumption exceeding available water
    with pytest.raises(ValidationError) as exc_info:
        FreshWater(
            fresh_water_bunkered=50.0,
            fresh_water_produced=50.0,
            fresh_water_consumed=150.0,
        )
    assert "Fresh water consumption cannot exceed available water" in str(exc_info.value)

    # Test consumption with remaining water
    with pytest.raises(ValidationError) as exc_info:
        FreshWater(
            fresh_water_bunkered=50.0,
            fresh_water_produced=50.0,
            fresh_water_remaining=20.0,
            fresh_water_consumed=150.0,
        )
    assert "Fresh water consumption cannot exceed available water" in str(exc_info.value)


def test_invalid_technical_water_consumption():
    """Test validation of technical water consumption."""
    with pytest.raises(ValidationError) as exc_info:
        FreshWater(
            technical_water_produced=100.0,
            technical_water_consumed=150.0,
        )
    assert "Technical water consumption cannot exceed production" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = FreshWater()
    assert info.fresh_water_bunkered is None
    assert info.fresh_water_produced is None
    assert info.fresh_water_consumed is None
    assert info.technical_water_produced is None
    assert info.technical_water_consumed is None
    assert info.wash_water_consumed is None
    assert info.fresh_water_remaining is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "fresh_water_bunkered": 100.0,
        "technical_water_produced": 200.0,
    }

    info = FreshWater(**data)
    assert info.fresh_water_bunkered == 100.0
    assert info.technical_water_produced == 200.0
    assert info.fresh_water_produced is None
    assert info.fresh_water_consumed is None
    assert info.technical_water_consumed is None
    assert info.wash_water_consumed is None
    assert info.fresh_water_remaining is None 