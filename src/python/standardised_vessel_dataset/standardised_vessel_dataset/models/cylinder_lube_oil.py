"""Cylinder lube oil information model for vessel data."""

from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class CylinderLubeOilInformation(BaseVesselModel):
    """Represent the "Cylinder Lube Oil Information" section of SVD."""

    remaining_on_board: Optional[float] = Field(
        None, description="Cylinder lube oil remaining on board based on Engine Room log entries, measured in metric tons."
    )
    feed_rate: Optional[float] = Field(
        None, description="Rate of feed of lube oil into the cylinder, measured in grams per kilowatt hour (g/kWh)."
    )
    consumption: Optional[float] = Field(
        None, description="Lube oil consumption in grams per hour per unit of output measured in kilowatts of the engine (g/kWh)."
    )
    received_during_bunkering: Optional[float] = Field(
        None, description="Lube oil received during bunkering, measured in metric tons."
    )

    @field_validator(
        "remaining_on_board",
        "feed_rate",
        "consumption",
        "received_during_bunkering",
    )
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v 