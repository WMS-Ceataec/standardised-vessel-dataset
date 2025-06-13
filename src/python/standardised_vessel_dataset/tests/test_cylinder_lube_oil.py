"""Tests for the CylinderLubeOilInformation model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.cylinder_lube_oil import CylinderLubeOilInformation


def test_valid_cylinder_lube_oil_information():
    """Test creating a valid CylinderLubeOilInformation instance."""
    data = {
        "remaining_on_board": 10.5,
        "feed_rate": 0.8,
        "consumption": 0.7,
        "received_during_bunkering": 5.0,
    }

    info = CylinderLubeOilInformation(**data)
    assert info.remaining_on_board == 10.5
    assert info.feed_rate == 0.8
    assert info.consumption == 0.7
    assert info.received_during_bunkering == 5.0


def test_invalid_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        CylinderLubeOilInformation(remaining_on_board=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        CylinderLubeOilInformation(feed_rate=-0.5)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        CylinderLubeOilInformation(consumption=-0.3)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        CylinderLubeOilInformation(received_during_bunkering=-2.0)
    assert "Value must be non-negative" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = CylinderLubeOilInformation()
    assert info.remaining_on_board is None
    assert info.feed_rate is None
    assert info.consumption is None
    assert info.received_during_bunkering is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "remaining_on_board": 10.5,
        "feed_rate": 0.8,
    }

    info = CylinderLubeOilInformation(**data)
    assert info.remaining_on_board == 10.5
    assert info.feed_rate == 0.8
    assert info.consumption is None
    assert info.received_during_bunkering is None 