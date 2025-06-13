"""Base models for the Standardised Vessel Dataset."""

from datetime import datetime
from typing import Any, Optional

from pydantic import BaseModel, Field, field_validator


class BaseVesselModel(BaseModel):
    """Base model for all vessel data models."""

    def to_dict(self) -> dict[str, Any]:
        """Convert the model to a dictionary."""
        return self.model_dump()

    @classmethod
    def from_dict(cls, data: dict[str, Any]) -> "BaseVesselModel":
        """Create a model instance from a dictionary."""
        return cls.model_validate(data)


class TimeStampedModel(BaseVesselModel):
    """Base model for time-stamped data."""

    timestamp: datetime = Field(..., description="The timestamp of the data point")
    source: str = Field(..., description="The source of the data")
    notes: Optional[str] = Field(None, description="Additional notes about the data")

    @field_validator("timestamp")
    @classmethod
    def validate_timestamp(cls, v: datetime) -> datetime:
        """Validate that the timestamp is not in the future."""
        if v > datetime.now():
            raise ValueError("Timestamp cannot be in the future")
        return v 