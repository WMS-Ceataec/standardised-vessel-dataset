"""Tests for the ArrivalTimes model."""

from datetime import datetime, timedelta

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.arrival_times import ArrivalTimes


def test_valid_arrival_times():
    """Test creating a valid ArrivalTimes instance."""
    now = datetime.now()
    departure = now - timedelta(hours=24)
    arrival = now + timedelta(hours=24)

    data = {
        "arrival": arrival,
        "departure": departure,
        "location_eta": arrival,
        "location_actual": arrival,
        "pilot_boarding_place_eta": arrival - timedelta(hours=1),
        "pilot_boarding_place_actual": arrival - timedelta(hours=1),
        "vts_eta": arrival - timedelta(hours=2),
        "vts_actual": arrival - timedelta(hours=2),
        "next_port_eta": arrival + timedelta(hours=48),
        "voyage_time": 48,
    }

    info = ArrivalTimes(**data)
    assert info.arrival == arrival
    assert info.departure == departure
    assert info.voyage_time == 48


def test_invalid_voyage_time():
    """Test validation of voyage time."""
    with pytest.raises(ValidationError) as exc_info:
        ArrivalTimes(voyage_time=-1)
    assert "Voyage time must be non-negative" in str(exc_info.value)


def test_invalid_actual_times():
    """Test validation of actual times."""
    future_time = datetime.now() + timedelta(days=1)

    with pytest.raises(ValidationError) as exc_info:
        ArrivalTimes(arrival=future_time)
    assert "Actual time cannot be in the future" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        ArrivalTimes(departure=future_time)
    assert "Actual time cannot be in the future" in str(exc_info.value)


def test_invalid_eta_times():
    """Test validation of ETA times."""
    now = datetime.now()
    departure = now
    eta = now - timedelta(hours=1)  # ETA before departure

    with pytest.raises(ValidationError) as exc_info:
        ArrivalTimes(departure=departure, location_eta=eta)
    assert "ETA time must be after departure time" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        ArrivalTimes(departure=departure, next_port_eta=eta)
    assert "ETA time must be after departure time" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = ArrivalTimes()
    assert info.arrival is None
    assert info.departure is None
    assert info.voyage_time is None


def test_partial_information():
    """Test creating an instance with partial information."""
    now = datetime.now()
    data = {
        "departure": now,
        "next_port_eta": now + timedelta(hours=24),
    }

    info = ArrivalTimes(**data)
    assert info.departure == now
    assert info.next_port_eta == now + timedelta(hours=24)
    assert info.arrival is None
    assert info.voyage_time is None 