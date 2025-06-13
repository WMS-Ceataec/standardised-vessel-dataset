"""Deviation from planned model for vessel data."""

from datetime import datetime
from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class DeviationFromPlanned(BaseVesselModel):
    """Represent the "Deviation From Planned" section of SVD."""

    reason: Optional[str] = Field(None, description="Description of why the ship has deviated from the planned voyage.")
    latitude: Optional[float] = Field(
        None, description="Latitude (geographical coordinate) of the location of the ship at the time of deviation."
    )
    longitude: Optional[float] = Field(
        None, description="Longitude (geographical coordinate) of the location of the ship at the time of deviation."
    )
    ship_deviation_started_time: Optional[datetime] = Field(
        None, description="Date and time when the ship started its deviation from the planned voyage."
    )
    ship_deviation_stopped_time: Optional[datetime] = Field(
        None, description="Date and time when the ship stopped its deviation from the planned voyage."
    )

    @field_validator("latitude")
    @classmethod
    def validate_latitude(cls, v: Optional[float]) -> Optional[float]:
        """Validate that latitude is between -90 and 90 degrees."""
        if v is not None and (v < -90 or v > 90):
            raise ValueError("Latitude must be between -90 and 90 degrees")
        return v

    @field_validator("longitude")
    @classmethod
    def validate_longitude(cls, v: Optional[float]) -> Optional[float]:
        """Validate that longitude is between -180 and 180 degrees."""
        if v is not None and (v < -180 or v > 180):
            raise ValueError("Longitude must be between -180 and 180 degrees")
        return v

    @field_validator("ship_deviation_stopped_time")
    @classmethod
    def validate_deviation_times(cls, v: Optional[datetime], values: dict) -> Optional[datetime]:
        """Validate that deviation stopped time is after started time."""
        if v is not None and values.get("ship_deviation_started_time") is not None:
            if v < values["ship_deviation_started_time"]:
                raise ValueError("Deviation stopped time must be after started time")
        return v

    @field_validator("ship_deviation_started_time", "ship_deviation_stopped_time")
    @classmethod
    def validate_deviation_times_not_future(cls, v: Optional[datetime]) -> Optional[datetime]:
        """Validate that deviation times are not in the future."""
        if v is not None and v > datetime.now():
            raise ValueError("Deviation time cannot be in the future")
        return v 