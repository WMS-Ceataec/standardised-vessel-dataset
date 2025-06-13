"""Tests for the CargoInformation model."""

from datetime import datetime, timedelta

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.cargo_information import CargoInformation


def test_valid_cargo_information():
    """Test creating a valid CargoInformation instance."""
    data = {
        "cargo_description": "General cargo",
        "gross_weight": 1000.0,
        "gross_volume": 500.0,
        "bill_of_lading_reference": "BOL123",
        "bill_of_lading_issued_date": datetime.now() - timedelta(days=1),
        "total_containers_teu": 100,
        "total_full_containers_teu": 80,
        "total_full_reefer_containers_teu": 20,
        "reefer_sockets_in_use": 20,
        "chilled_20ft_reefer_containers": 5,
        "chilled_40ft_reefer_containers": 5,
        "frozen_20ft_reefer_containers": 5,
        "frozen_40ft_reefer_containers": 5,
        "total_vehicles_ceu": 50,
    }

    info = CargoInformation(**data)
    assert info.cargo_description == "General cargo"
    assert info.gross_weight == 1000.0
    assert info.total_containers_teu == 100
    assert info.total_vehicles_ceu == 50


def test_invalid_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        CargoInformation(gross_weight=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        CargoInformation(total_containers_teu=-1)
    assert "Value must be non-negative" in str(exc_info.value)


def test_invalid_bill_of_lading_date():
    """Test validation of bill of lading issue date."""
    future_date = datetime.now() + timedelta(days=1)

    with pytest.raises(ValidationError) as exc_info:
        CargoInformation(bill_of_lading_issued_date=future_date)
    assert "Bill of lading issue date cannot be in the future" in str(exc_info.value)


def test_invalid_container_counts():
    """Test validation of container counts."""
    with pytest.raises(ValidationError) as exc_info:
        CargoInformation(total_containers_teu=100, total_full_containers_teu=150)
    assert "Total full containers cannot be greater than total containers" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        CargoInformation(total_full_containers_teu=100, total_full_reefer_containers_teu=150)
    assert "Total full reefer containers cannot be greater than total full containers" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = CargoInformation()
    assert info.cargo_description is None
    assert info.gross_weight is None
    assert info.total_containers_teu is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "cargo_description": "General cargo",
        "total_containers_teu": 100,
    }

    info = CargoInformation(**data)
    assert info.cargo_description == "General cargo"
    assert info.total_containers_teu == 100
    assert info.gross_weight is None
    assert info.total_vehicles_ceu is None 