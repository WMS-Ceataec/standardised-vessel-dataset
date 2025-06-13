"""Emissions model for vessel data."""

from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class Emissions(BaseVesselModel):
    """Represents emissions data including CO2, CH4, and N2O metrics and conversion factors."""

    # CO2 emissions
    total_co2: Optional[float] = Field(
        None,
        description="The total amount of Carbon Dioxide refers to the comprehensive sum of CO2, including its equivalents derived from all emissions (but without deducting the CO2 equivalent captured), quantified in metric tons of CO2 equivalent.",
    )
    total_co2_percentage: Optional[float] = Field(
        None,
        description="Proportion of Carbon Dioxide emissions that are emitted while at sea, taking into account the amount that is successfully captured, measured in percentage.",
    )
    total_co2_tank_to_wake: Optional[float] = Field(
        None, description="Total amount of Carbon Dioxide from fuels (tank-to-wake), measured in metric tons."
    )
    total_co2_captured: Optional[float] = Field(
        None, description="Total amount of Carbon Dioxide equivalent captured, measured in metric tons."
    )

    # CH4 emissions
    total_ch4: Optional[float] = Field(None, description="Total aggregated amount of Methane emitted, measured in metric tons.")
    total_ch4_converted_to_co2: Optional[float] = Field(
        None, description="The CO2 equivalent converted from CH4 emissions, measured in metric tons of CO2 equivalent."
    )

    # N2O emissions
    total_n2o: Optional[float] = Field(None, description="Total aggregated amount of Nitrous Oxide emitted, measured in metric tons.")
    total_n2o_converted_to_co2: Optional[float] = Field(
        None, description="The CO2 equivalent converted from N2O emissions, measured in metric tons of CO2 equivalent."
    )

    # Conversion factors
    ch4_emission_conversion_factor: Optional[float] = Field(
        None, description="CH4 emission conversion factor, expressed in emissions per gram of fuel (gCH4/gfuel)."
    )
    n2o_emission_conversion_factor: Optional[float] = Field(
        None, description="N2O emission conversion factor, expressed in emissions per gram of fuel (gN2O/gfuel)."
    )

    @field_validator(
        "total_co2",
        "total_co2_tank_to_wake",
        "total_co2_captured",
        "total_ch4",
        "total_ch4_converted_to_co2",
        "total_n2o",
        "total_n2o_converted_to_co2",
    )
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that emission values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Emission value must be non-negative")
        return v

    @field_validator("total_co2_percentage")
    @classmethod
    def validate_percentage(cls, v: Optional[float]) -> Optional[float]:
        """Validate that percentage is between 0 and 100."""
        if v is not None and (v < 0 or v > 100):
            raise ValueError("Percentage must be between 0 and 100")
        return v

    @field_validator("ch4_emission_conversion_factor", "n2o_emission_conversion_factor")
    @classmethod
    def validate_conversion_factor(cls, v: Optional[float]) -> Optional[float]:
        """Validate that conversion factors are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Conversion factor must be non-negative")
        return v 