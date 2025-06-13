"""Tests for the PortInformation model."""

import pytest

from standardised_vessel_dataset.models.port import PortInformation


def test_valid_port_information():
    """Test creating a valid PortInformation instance."""
    data = {
        "departure_port_code": "SGSIN",
        "departure_port_name": "Singapore",
        "arrival_port_code": "HKHKG",
        "arrival_port_name": "Hong Kong",
        "inbound_port_jurisdiction_code": "HK",
        "outbound_port_jurisdiction_code": "SG",
        "pilot_boarding_place_name": "Pilot Station 1",
        "pilot_boarding_place_location": "1.2833° N, 103.8333° E",
        "berth_name": "Berth 1",
    }

    info = PortInformation(**data)
    assert info.departure_port_code == "SGSIN"
    assert info.arrival_port_code == "HKHKG"
    assert info.berth_name == "Berth 1"


def test_optional_fields():
    """Test that all fields are optional."""
    info = PortInformation()
    assert info.departure_port_code is None
    assert info.arrival_port_code is None
    assert info.berth_name is None


def test_partial_information():
    """Test creating an instance with partial information."""
    data = {
        "departure_port_code": "SGSIN",
        "arrival_port_code": "HKHKG",
    }

    info = PortInformation(**data)
    assert info.departure_port_code == "SGSIN"
    assert info.arrival_port_code == "HKHKG"
    assert info.departure_port_name is None
    assert info.arrival_port_name is None 