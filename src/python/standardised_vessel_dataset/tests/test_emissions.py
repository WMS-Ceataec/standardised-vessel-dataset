"""Tests for the Emissions model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.emissions import Emissions


def test_valid_emissions():
    """Test creating a valid Emissions instance."""
    data = {
        "total_co2": 1000.0,
        "total_co2_percentage": 75.5,
        "total_co2_tank_to_wake": 900.0,
        "total_co2_captured": 100.0,
        "total_ch4": 5.0,
        "total_ch4_converted_to_co2": 125.0,
        "total_n2o": 2.0,
        "total_n2o_converted_to_co2": 600.0,
        "ch4_emission_conversion_factor": 0.001,
        "n2o_emission_conversion_factor": 0.0005,
    }

    info = Emissions(**data)
    assert info.total_co2 == 1000.0
    assert info.total_co2_percentage == 75.5
    assert info.total_ch4 == 5.0
    assert info.total_n2o == 2.0
    assert info.ch4_emission_conversion_factor == 0.001


def test_invalid_negative_emissions():
    """Test validation of non-negative emission values."""
    with pytest.raises(ValidationError) as exc_info:
        Emissions(total_co2=-1.0)
    assert "Emission value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        Emissions(total_ch4=-0.5)
    assert "Emission value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        Emissions(total_n2o=-0.2)
    assert "Emission value must be non-negative" in str(exc_info.value)


def test_invalid_percentage():
    """Test validation of percentage values."""
    with pytest.raises(ValidationError) as exc_info:
        Emissions(total_co2_percentage=-1.0)
    assert "Percentage must be between 0 and 100" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        Emissions(total_co2_percentage=101.0)
    assert "Percentage must be between 0 and 100" in str(exc_info.value)


def test_invalid_conversion_factors():
    """Test validation of conversion factors."""
    with pytest.raises(ValidationError) as exc_info:
        Emissions(ch4_emission_conversion_factor=-0.001)
    assert "Conversion factor must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        Emissions(n2o_emission_conversion_factor=-0.0005)
    assert "Conversion factor must be non-negative" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = Emissions()
    assert info.total_co2 is None
    assert info.total_co2_percentage is None
    assert info.total_ch4 is None
    assert info.total_n2o is None
    assert info.ch4_emission_conversion_factor is None
    assert info.n2o_emission_conversion_factor is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "total_co2": 1000.0,
        "total_co2_percentage": 75.5,
    }

    info = Emissions(**data)
    assert info.total_co2 == 1000.0
    assert info.total_co2_percentage == 75.5
    assert info.total_ch4 is None
    assert info.total_n2o is None
    assert info.ch4_emission_conversion_factor is None
    assert info.n2o_emission_conversion_factor is None 