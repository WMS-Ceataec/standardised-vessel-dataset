"""Tests for the WeatherInformation model."""

import pytest
from pydantic import ValidationError

from standardised_vessel_dataset.models.weather import WeatherInformation


def test_valid_weather_information():
    """Test creating a valid WeatherInformation instance."""
    data = {
        "weather_remarks": "Clear skies, calm seas",
        "bad_weather_hours": 12.5,
        "bad_weather_distance": 150.0,
        "wind_force": 4,
        "wind_speed": "15",
        "wind_direction": "NE",
        "wind_direction_estimated_relative": 45.0,
        "wind_direction_estimated": 45.0,
        "air_temperature": 25.5,
        "atmospheric_pressure": 1.013,
        "state_of_sea": "3",
        "sea_direction_relative": 90.0,
        "sea_direction": 90.0,
        "sea_height": 2.5,
        "swell_direction_relative": 135.0,
        "swell_direction": 135.0,
        "swell_height": 1.5,
        "ocean_current_direction_relative": 180.0,
        "ocean_current_direction": 180.0,
        "ocean_current_direction_weather_provider": 180.0,
    }

    info = WeatherInformation(**data)
    assert info.weather_remarks == "Clear skies, calm seas"
    assert info.wind_force == 4
    assert info.sea_height == 2.5


def test_invalid_wind_force():
    """Test validation of wind force values."""
    with pytest.raises(ValidationError) as exc_info:
        WeatherInformation(wind_force=13)
    assert "Wind force must be between 0 and 12" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        WeatherInformation(wind_force=-1)
    assert "Wind force must be between 0 and 12" in str(exc_info.value)


def test_invalid_directions():
    """Test validation of direction values."""
    invalid_directions = [
        "wind_direction_estimated_relative",
        "wind_direction_estimated",
        "sea_direction_relative",
        "sea_direction",
        "swell_direction_relative",
        "swell_direction",
        "ocean_current_direction_relative",
        "ocean_current_direction",
        "ocean_current_direction_weather_provider",
    ]

    for field in invalid_directions:
        with pytest.raises(ValidationError) as exc_info:
            WeatherInformation(**{field: 361.0})
        assert "Direction must be between 0 and 360 degrees" in str(exc_info.value)

        with pytest.raises(ValidationError) as exc_info:
            WeatherInformation(**{field: -1.0})
        assert "Direction must be between 0 and 360 degrees" in str(exc_info.value)


def test_invalid_heights():
    """Test validation of height values."""
    with pytest.raises(ValidationError) as exc_info:
        WeatherInformation(sea_height=-1.0)
    assert "Height must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        WeatherInformation(swell_height=-0.5)
    assert "Height must be non-negative" in str(exc_info.value)


def test_invalid_non_negative_values():
    """Test validation of non-negative values."""
    with pytest.raises(ValidationError) as exc_info:
        WeatherInformation(bad_weather_hours=-1.0)
    assert "Value must be non-negative" in str(exc_info.value)

    with pytest.raises(ValidationError) as exc_info:
        WeatherInformation(bad_weather_distance=-10.0)
    assert "Value must be non-negative" in str(exc_info.value)


def test_optional_fields():
    """Test that all fields are optional."""
    info = WeatherInformation()
    assert info.weather_remarks is None
    assert info.wind_force is None
    assert info.sea_height is None 