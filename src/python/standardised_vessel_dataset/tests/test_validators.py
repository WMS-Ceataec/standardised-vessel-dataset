"""Tests for the validators."""

import pytest
from datetime import datetime, timedelta

from standardised_vessel_dataset.validators.dataset import DatasetValidator
from standardised_vessel_dataset.validators.general import GeneralValidator


def test_valid_general_information():
    """Test validation of valid general information."""
    data = {
        "vessel_imo": "1234567",
        "vessel_name": "Test Vessel",
        "reporting_period_start": datetime.now(),
        "reporting_period_end": datetime.now() + timedelta(days=1),
    }

    validator = GeneralValidator()
    result = validator.validate(data)
    assert result.is_valid
    assert not result.errors


def test_invalid_imo():
    """Test validation of invalid IMO number."""
    data = {
        "vessel_imo": "123456",  # Too short
        "vessel_name": "Test Vessel",
    }

    validator = GeneralValidator()
    result = validator.validate(data)
    assert not result.is_valid
    assert any("IMO must be seven digits" in err for err in result.errors)

    data["vessel_imo"] = "12345678"  # Too long
    result = validator.validate(data)
    assert not result.is_valid
    assert any("IMO must be seven digits" in err for err in result.errors)

    data["vessel_imo"] = "123456a"  # Not all digits
    result = validator.validate(data)
    assert not result.is_valid
    assert any("IMO must be seven digits" in err for err in result.errors)


def test_invalid_vessel_name():
    """Test validation of invalid vessel name."""
    data = {
        "vessel_imo": "1234567",
        "vessel_name": "",  # Empty name
    }

    validator = GeneralValidator()
    result = validator.validate(data)
    assert not result.is_valid
    assert any("Vessel name is required" in err for err in result.errors)


def test_invalid_reporting_period():
    """Test validation of invalid reporting period."""
    now = datetime.now()
    data = {
        "vessel_imo": "1234567",
        "vessel_name": "Test Vessel",
        "reporting_period_start": now + timedelta(days=1),
        "reporting_period_end": now,  # End before start
    }

    validator = GeneralValidator()
    result = validator.validate(data)
    assert not result.is_valid
    assert any("Reporting period start must be before end" in err for err in result.errors)


def test_valid_dataset():
    """Test validation of valid dataset."""
    data = {
        "vessel_imo": "1234567",
        "vessel_name": "Test Vessel",
        "reporting_period_start": datetime.now(),
        "reporting_period_end": datetime.now() + timedelta(days=1),
        "general_information": {
            "vessel_imo": "1234567",
            "vessel_name": "Test Vessel",
            "reporting_period_start": datetime.now(),
            "reporting_period_end": datetime.now() + timedelta(days=1),
        },
    }

    validator = DatasetValidator()
    result = validator.validate(data)
    assert result.is_valid
    assert not result.errors


def test_invalid_dataset():
    """Test validation of invalid dataset."""
    data = {
        "vessel_imo": "123456",  # Invalid IMO
        "vessel_name": "",  # Invalid name
        "general_information": {
            "vessel_imo": "123456",  # Invalid IMO
            "vessel_name": "",  # Invalid name
        },
    }

    validator = DatasetValidator()
    result = validator.validate(data)
    assert not result.is_valid
    assert len(result.errors) > 0 