"""Arrival times model for the Standardised Vessel Dataset."""

from datetime import datetime, timedelta
from typing import Optional

from pydantic import BaseModel, Field, field_validator


class ArrivalTimes(BaseModel):
    """Arrival times model for the Standardised Vessel Dataset."""

    arrival: Optional[datetime] = Field(None, description="Actual arrival time")
    departure: Optional[datetime] = Field(None, description="Actual departure time")
    location_eta: Optional[datetime] = Field(None, description="ETA at location")
    location_actual: Optional[datetime] = Field(None, description="Actual arrival time at location")
    pilot_boarding_place_eta: Optional[datetime] = Field(None, description="ETA at pilot boarding place")
    pilot_boarding_place_actual: Optional[datetime] = Field(None, description="Actual arrival time at pilot boarding place")
    vts_eta: Optional[datetime] = Field(None, description="ETA at VTS")
    vts_actual: Optional[datetime] = Field(None, description="Actual arrival time at VTS")
    next_port_eta: Optional[datetime] = Field(None, description="ETA at next port")
    voyage_time: Optional[int] = Field(None, description="Voyage time in hours")

    @field_validator("arrival", "location_actual", "pilot_boarding_place_actual", "vts_actual")
    @classmethod
    def validate_actual_times(cls, v: Optional[datetime]) -> Optional[datetime]:
        """Validate that actual times are not in the future."""
        if v is not None and v > datetime.now():
            raise ValueError("Actual time cannot be in the future")
        return v

    @field_validator("location_eta", "pilot_boarding_place_eta", "vts_eta", "next_port_eta")
    @classmethod
    def validate_eta_times(cls, v: Optional[datetime], values: dict) -> Optional[datetime]:
        """Validate that ETA times are after departure time if departure time is provided."""
        if v is not None and "departure" in values.data and values.data["departure"] is not None:
            if v < values.data["departure"]:
                raise ValueError("ETA time must be after departure time")
        return v

    @field_validator("voyage_time")
    @classmethod
    def validate_voyage_time(cls, v: Optional[int]) -> Optional[int]:
        """Validate that voyage time is non-negative."""
        if v is not None and v < 0:
            raise ValueError("Voyage time must be non-negative")
        return v 