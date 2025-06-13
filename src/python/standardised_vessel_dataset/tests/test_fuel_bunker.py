"""Tests for the FuelAndBunkerInformation model."""

from datetime import datetime

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.fuel_bunker import FuelAndBunkerInformation


def test_valid_fuel_bunker_information():
    """Test creating a valid FuelAndBunkerInformation instance."""
    data = {
        "fuel_type": "HFO",
        "fuel_type_trade_name": "IFO 380",
        "bunker_delivery_note_number": "BDN123456",
        "bunker_delivery_datetime": datetime(2024, 1, 1, 12, 0),
        "fuel_proof_of_sustainability_reference": "POS123456",
        "fuel_bunkered": 1000.0,
        "fuel_mass": 1000.0,
        "fuel_density": 0.991,
        "fuel_sulphur_content": 0.5,
        "fuel_viscosity": 380.0,
        "fuel_water_content": 0.1,
        "fuel_higher_heating_value": 42.0,
        "fuel_lower_heating_value": 40.0,
        "fuel_calorific_value_reporting_scheme_code": "IMO",
        "fuel_lower_calorific_value": 40.0,
        "fuel_grade": "ISO 8217:2017",
        "fuel_ghg_intensity_imo_manual": 3.114,
        "fuel_ghg_intensity_imo_voyage": 3.114,
        "fuel_bunker_port": "SGSIN",
        "fuel_bunker_port_name": "Singapore",
        "fuel_carbon_dioxide_emission": 3.114,
        "total_fuel_consumed": 800.0,
        "fuel_consumed_by_main_engine": 600.0,
        "fuel_consumed_by_diesel_electric_propulsion": 0.0,
        "fuel_consumed_by_diesel_generator": 100.0,
        "fuel_consumed_by_auxiliary_boiler": 50.0,
        "fuel_consumed_by_auxiliary_engine": 0.0,
        "fuel_consumed_by_cargo_heating": 0.0,
        "fuel_consumed_by_reefer_containers": 20.0,
        "fuel_consumed_by_discharge_pump": 0.0,
        "fuel_consumed_by_other_devices": 30.0,
        "fuel_remaining_on_board": 200.0,
        "sludge_remaining_on_board": 5.0,
    }

    info = FuelAndBunkerInformation(**data)
    assert info.fuel_type == "HFO"
    assert info.fuel_bunkered == 1000.0
    assert info.fuel_remaining_on_board == 200.0


def test_invalid_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        FuelAndBunkerInformation(fuel_bunkered=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        FuelAndBunkerInformation(fuel_remaining_on_board=-100.0)
    assert "Value must be non-negative" in str(exc_info.value)


def test_invalid_percentage_values():
    """Test validation of percentage values."""
    with pytest.raises(ValidationError) as exc_info:
        FuelAndBunkerInformation(fuel_sulphur_content=101.0)
    assert "Percentage must be between 0 and 100" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        FuelAndBunkerInformation(fuel_water_content=-1.0)
    assert "Percentage must be between 0 and 100" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = FuelAndBunkerInformation()
    assert info.fuel_type is None
    assert info.fuel_bunkered is None
    assert info.fuel_remaining_on_board is None


def test_fuel_consumption_sum():
    """Test that total fuel consumption matches sum of components."""
    data = {
        "fuel_consumed_by_main_engine": 600.0,
        "fuel_consumed_by_diesel_electric_propulsion": 0.0,
        "fuel_consumed_by_diesel_generator": 100.0,
        "fuel_consumed_by_auxiliary_boiler": 50.0,
        "fuel_consumed_by_auxiliary_engine": 0.0,
        "fuel_consumed_by_cargo_heating": 0.0,
        "fuel_consumed_by_reefer_containers": 20.0,
        "fuel_consumed_by_discharge_pump": 0.0,
        "fuel_consumed_by_other_devices": 30.0,
        "total_fuel_consumed": 800.0,
    }

    info = FuelAndBunkerInformation(**data)
    components_sum = sum(
        [
            info.fuel_consumed_by_main_engine,
            info.fuel_consumed_by_diesel_electric_propulsion,
            info.fuel_consumed_by_diesel_generator,
            info.fuel_consumed_by_auxiliary_boiler,
            info.fuel_consumed_by_auxiliary_engine,
            info.fuel_consumed_by_cargo_heating,
            info.fuel_consumed_by_reefer_containers,
            info.fuel_consumed_by_discharge_pump,
            info.fuel_consumed_by_other_devices,
        ]
    )
    assert abs(components_sum - info.total_fuel_consumed) < 0.001 