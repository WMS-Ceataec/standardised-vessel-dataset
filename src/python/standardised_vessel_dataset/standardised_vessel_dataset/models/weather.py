"""Weather information model for vessel data."""

from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class WeatherInformation(BaseVesselModel):
    """Represent the "Weather Information" section of SVD."""

    weather_remarks: Optional[str] = Field(
        None, description="Brief details of weather and sea conditions prevailing."
    )
    bad_weather_hours: Optional[float] = Field(
        None,
        description="Duration, in hours, during which the weather conditions are unfavourable or challenging in sea state above Beaufort scale 4 (manual observation).",
    )
    bad_weather_distance: Optional[float] = Field(
        None,
        description="Number of nautical miles experienced when sea state above Beaufort scale 4 (manual observation).",
    )
    wind_force: Optional[int] = Field(
        None,
        description="Force of wind on Beaufort Scale as measured by on board ship weather station, over the time of reporting (scale from 0-12).",
    )
    wind_speed: Optional[str] = Field(
        None, description="Code indicating the wind speed, in units indicated in Iw."
    )
    wind_direction: Optional[str] = Field(
        None,
        description="Code indicating the true direction, in tens of degrees, from which wind is blowing (or will blow).",
    )
    wind_direction_estimated_relative: Optional[float] = Field(
        None,
        description="Best estimate of the direction of wind relative to the ship, in degrees, made by the seafarer on board.",
    )
    wind_direction_estimated: Optional[float] = Field(
        None,
        description="Best estimate of the direction of wind relative to the ship, in degrees true, made by the seafarer on board.",
    )
    air_temperature: Optional[float] = Field(
        None, description="Measure of air temperature in degrees Celsius at ship location."
    )
    atmospheric_pressure: Optional[float] = Field(
        None, description="Measure of the barometric pressure of the ship environment, in bars."
    )
    state_of_sea: Optional[str] = Field(
        None, description="Code indicating the state of the sea by significant wave height."
    )
    sea_direction_relative: Optional[float] = Field(
        None,
        description="Best estimate of the direction of sea relative to the ship, in degrees, made by the seafarer on board.",
    )
    sea_direction: Optional[float] = Field(
        None,
        description="Best estimate of the direction of sea, in degrees true, made by the seafarer on board.",
    )
    sea_height: Optional[float] = Field(
        None, description="Recorded sea height in metres (as per weather provider)."
    )
    swell_direction_relative: Optional[float] = Field(
        None,
        description="Best estimate of the direction of swell relative to the ship, in degrees, made by the seafarer on board.",
    )
    swell_direction: Optional[float] = Field(
        None,
        description="Best estimate of the direction of swell, in degrees true, made by the seafarer on board.",
    )
    swell_height: Optional[float] = Field(
        None, description="Recorded swell height in metres (as per weather provider)."
    )
    ocean_current_direction_relative: Optional[float] = Field(
        None,
        description="Best estimate of the direction of ocean current relative to the ship, in degrees, made by the seafarer on board.",
    )
    ocean_current_direction: Optional[float] = Field(
        None,
        description="Best estimate of the direction of ocean current, in degrees true, made by the seafarer on board.",
    )
    ocean_current_direction_weather_provider: Optional[float] = Field(
        None,
        description="Direction of ocean current, in degrees, as per weather provider, if different.",
    )

    @field_validator("wind_force")
    @classmethod
    def validate_wind_force(cls, v: Optional[int]) -> Optional[int]:
        """Validate wind force is within Beaufort scale range (0-12)."""
        if v is not None and not 0 <= v <= 12:
            raise ValueError("Wind force must be between 0 and 12 (Beaufort scale)")
        return v

    @field_validator(
        "wind_direction_estimated_relative",
        "wind_direction_estimated",
        "sea_direction_relative",
        "sea_direction",
        "swell_direction_relative",
        "swell_direction",
        "ocean_current_direction_relative",
        "ocean_current_direction",
        "ocean_current_direction_weather_provider",
    )
    @classmethod
    def validate_direction(cls, v: Optional[float]) -> Optional[float]:
        """Validate direction is within valid range (0-360 degrees)."""
        if v is not None and not 0 <= v <= 360:
            raise ValueError("Direction must be between 0 and 360 degrees")
        return v

    @field_validator("bad_weather_hours", "bad_weather_distance")
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v

    @field_validator("sea_height", "swell_height")
    @classmethod
    def validate_height(cls, v: Optional[float]) -> Optional[float]:
        """Validate height values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Height must be non-negative")
        return v 