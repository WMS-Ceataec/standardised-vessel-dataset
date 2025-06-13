"""Tests for the GeneralInformation model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.general import GeneralInformation


def test_valid_general_information():
    """Test creating a valid GeneralInformation instance."""
    data = {
        "mmsi": "123456789",
        "call_sign": "ABCD",
        "flag": "Panama",
        "home_port": "Panama City",
        "length_overall": 200.0,
        "beam": 32.0,
        "draft": 12.0,
        "gross_tonnage": 50000.0,
        "net_tonnage": 25000.0,
        "deadweight": 40000.0,
        "main_engine_type": "Diesel",
        "main_engine_power": 20000.0,
        "main_engine_fuel_type": "HFO",
        "auxiliary_engine_count": 3,
        "auxiliary_engine_power": 3000.0,
        "crew_count": 20,
        "passenger_count": 0,
        "ice_class": "1A",
        "eedi": 5.0,
        "eexi": 4.5,
        "carbon_intensity_indicator": 3.8,
        "attained_cii": 3.5,
        "required_cii": 4.0,
        "cii_rating": "B",
    }

    info = GeneralInformation(**data)
    assert info.mmsi == "123456789"
    assert info.length_overall == 200.0
    assert info.cii_rating == "B"


def test_invalid_dimensions():
    """Test validation of vessel dimensions."""
    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(length_overall=-1.0)
    assert "Dimension must be positive" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(beam=0.0)
    assert "Dimension must be positive" in str(exc_info.value)


def test_invalid_tonnage():
    """Test validation of tonnage values."""
    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(gross_tonnage=-1000.0)
    assert "Tonnage must be positive" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(deadweight=0.0)
    assert "Tonnage must be positive" in str(exc_info.value)


def test_invalid_engine_power():
    """Test validation of engine power values."""
    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(main_engine_power=-1000.0)
    assert "Engine power must be positive" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(auxiliary_engine_power=0.0)
    assert "Engine power must be positive" in str(exc_info.value)


def test_invalid_counts():
    """Test validation of count values."""
    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(crew_count=-1)
    assert "Count must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(passenger_count=-5)
    assert "Count must be non-negative" in str(exc_info.value)


def test_invalid_cii_rating():
    """Test validation of CII rating."""
    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(cii_rating="F")
    assert "CII rating must be one of: A, B, C, D, E" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        GeneralInformation(cii_rating="X")
    assert "CII rating must be one of: A, B, C, D, E" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = GeneralInformation()
    assert info.mmsi is None
    assert info.length_overall is None
    assert info.cii_rating is None 