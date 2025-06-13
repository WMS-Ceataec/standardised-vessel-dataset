"""Tests for the ElectricityConsumption model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.electricity import ElectricityConsumption


def test_valid_electricity_consumption():
    """Test creating a valid ElectricityConsumption instance."""
    data = {
        "boiler_electricity_consumption": 1000.0,
        "generator_production": 2000.0,
        "offset_electricity_consumption": 100.0,
        "power_consumption_for_plant": 500.0,
        "electrical_for_cargo_cooling": 300.0,
        "electrical_for_discharge_pump": 200.0,
        "electrical_for_reefer_containers": 400.0,
        "electrical_from_on_shore_power_supply": 150.0,
        "electrical_from_zero_emissions_technologies": 50.0,
        "fuel_type_used_for_cargo_cooling": "HFO",
        "fuel_type_used_for_discharge_pump": "MDO",
        "fuel_type_used_for_reefer_containers": "MGO",
        "fuel_oil_consumption_for_cargo_cooling": 250.0,
        "fuel_oil_consumption_for_discharge_pump": 200.0,
        "fuel_oil_consumption_for_reefer_containers": 180.0,
    }

    info = ElectricityConsumption(**data)
    assert info.boiler_electricity_consumption == 1000.0
    assert info.generator_production == 2000.0
    assert info.fuel_type_used_for_cargo_cooling == "HFO"
    assert info.fuel_oil_consumption_for_cargo_cooling == 250.0


def test_invalid_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        ElectricityConsumption(boiler_electricity_consumption=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        ElectricityConsumption(generator_production=-100.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        ElectricityConsumption(fuel_oil_consumption_for_cargo_cooling=-50.0)
    assert "Value must be non-negative" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = ElectricityConsumption()
    assert info.boiler_electricity_consumption is None
    assert info.generator_production is None
    assert info.fuel_type_used_for_cargo_cooling is None
    assert info.fuel_oil_consumption_for_cargo_cooling is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "boiler_electricity_consumption": 1000.0,
        "fuel_type_used_for_cargo_cooling": "HFO",
    }

    info = ElectricityConsumption(**data)
    assert info.boiler_electricity_consumption == 1000.0
    assert info.fuel_type_used_for_cargo_cooling == "HFO"
    assert info.generator_production is None
    assert info.fuel_oil_consumption_for_cargo_cooling is None 