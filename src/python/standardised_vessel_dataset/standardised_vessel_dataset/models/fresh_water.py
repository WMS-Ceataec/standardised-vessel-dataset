"""Fresh water model for vessel data."""

from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class FreshWater(BaseVesselModel):
    """Represent the "Fresh Water" section of SVD."""

    # Fresh water metrics
    fresh_water_bunkered: Optional[float] = Field(
        None, description="Fresh water bunkered on board, measured in metric tons."
    )
    fresh_water_produced: Optional[float] = Field(
        None, description="Fresh water produced on board by running the fresh water generator, measured in metric tons."
    )
    fresh_water_consumed: Optional[float] = Field(
        None, description="Fresh water (drinking water) consumed on board, measured in metric tons."
    )
    fresh_water_remaining: Optional[float] = Field(
        None, description="Fresh drinking water remaining on board, measured in metric tons."
    )

    # Technical water metrics
    technical_water_produced: Optional[float] = Field(
        None, description="Technical water (< 15 ppm) produced on board, measured in metric tons."
    )
    technical_water_consumed: Optional[float] = Field(
        None, description="Technical water (< 15 ppm) consumed on board, measured in metric tons."
    )

    # Wash water metrics
    wash_water_consumed: Optional[float] = Field(
        None, description="Wash water (for exhaust gas cleaning systems) consumed on board, measured in metric tons."
    )

    @field_validator(
        "fresh_water_bunkered",
        "fresh_water_produced",
        "fresh_water_consumed",
        "fresh_water_remaining",
        "technical_water_produced",
        "technical_water_consumed",
        "wash_water_consumed",
    )
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v

    @field_validator("fresh_water_consumed")
    @classmethod
    def validate_consumption(cls, v: Optional[float], values: dict) -> Optional[float]:
        """Validate that consumption does not exceed available water."""
        if v is not None:
            available = 0.0
            if values.get("fresh_water_bunkered") is not None:
                available += values["fresh_water_bunkered"]
            if values.get("fresh_water_produced") is not None:
                available += values["fresh_water_produced"]
            if values.get("fresh_water_remaining") is not None:
                available += values["fresh_water_remaining"]
            if v > available:
                raise ValueError("Fresh water consumption cannot exceed available water")
        return v

    @field_validator("technical_water_consumed")
    @classmethod
    def validate_technical_consumption(cls, v: Optional[float], values: dict) -> Optional[float]:
        """Validate that technical water consumption does not exceed production."""
        if v is not None and values.get("technical_water_produced") is not None:
            if v > values["technical_water_produced"]:
                raise ValueError("Technical water consumption cannot exceed production")
        return v 