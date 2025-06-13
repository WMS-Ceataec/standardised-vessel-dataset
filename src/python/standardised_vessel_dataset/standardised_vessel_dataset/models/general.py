"""General information model for the Standardised Vessel Dataset."""

from typing import Optional

from pydantic import BaseModel, Field, field_validator


class GeneralInformation(BaseModel):
    """General information model for the Standardised Vessel Dataset."""

    # Vessel identification
    vessel_imo: Optional[str] = Field(None, description="IMO number of the vessel")
    vessel_name: Optional[str] = Field(None, description="Name of the vessel")
    mmsi: Optional[str] = Field(None, description="Maritime Mobile Service Identity")
    call_sign: Optional[str] = Field(None, description="Call sign of the vessel")
    flag: Optional[str] = Field(None, description="Flag state of the vessel")
    home_port: Optional[str] = Field(None, description="Home port of the vessel")

    # Vessel characteristics
    length_overall: Optional[float] = Field(None, description="Length overall in meters")
    beam: Optional[float] = Field(None, description="Beam in meters")
    draft: Optional[float] = Field(None, description="Draft in meters")
    gross_tonnage: Optional[float] = Field(None, description="Gross tonnage")
    net_tonnage: Optional[float] = Field(None, description="Net tonnage")
    deadweight: Optional[float] = Field(None, description="Deadweight in metric tons")

    # Engine information
    main_engine_type: Optional[str] = Field(None, description="Type of main engine")
    main_engine_power: Optional[float] = Field(None, description="Power of main engine in kW")
    main_engine_fuel_type: Optional[str] = Field(None, description="Fuel type of main engine")
    auxiliary_engine_count: Optional[int] = Field(None, description="Number of auxiliary engines")
    auxiliary_engine_power: Optional[float] = Field(None, description="Total power of auxiliary engines in kW")

    # Crew information
    crew_count: Optional[int] = Field(None, description="Number of crew members")
    passenger_count: Optional[int] = Field(None, description="Number of passengers")

    # Additional information
    ice_class: Optional[str] = Field(None, description="Ice class of the vessel")
    eedi: Optional[float] = Field(None, description="Energy Efficiency Design Index")
    eexi: Optional[float] = Field(None, description="Energy Efficiency Existing Ship Index")
    carbon_intensity_indicator: Optional[float] = Field(None, description="Carbon Intensity Indicator")
    attained_cii: Optional[float] = Field(None, description="Attained CII")
    required_cii: Optional[float] = Field(None, description="Required CII")
    cii_rating: Optional[str] = Field(None, description="CII rating (A-E)")

    @field_validator("length_overall", "beam", "draft")
    @classmethod
    def validate_dimensions(cls, v: Optional[float]) -> Optional[float]:
        """Validate that dimensions are positive."""
        if v is not None and v <= 0:
            raise ValueError("Dimension must be positive")
        return v

    @field_validator("gross_tonnage", "net_tonnage", "deadweight")
    @classmethod
    def validate_tonnage(cls, v: Optional[float]) -> Optional[float]:
        """Validate that tonnage values are positive."""
        if v is not None and v <= 0:
            raise ValueError("Tonnage must be positive")
        return v

    @field_validator("main_engine_power", "auxiliary_engine_power")
    @classmethod
    def validate_engine_power(cls, v: Optional[float]) -> Optional[float]:
        """Validate that engine power is positive."""
        if v is not None and v <= 0:
            raise ValueError("Engine power must be positive")
        return v

    @field_validator("crew_count", "passenger_count", "auxiliary_engine_count")
    @classmethod
    def validate_counts(cls, v: Optional[int]) -> Optional[int]:
        """Validate that counts are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Count must be non-negative")
        return v

    @field_validator("cii_rating")
    @classmethod
    def validate_cii_rating(cls, v: Optional[str]) -> Optional[str]:
        """Validate that CII rating is one of A-E."""
        if v is not None and v not in ["A", "B", "C", "D", "E"]:
            raise ValueError("CII rating must be one of A-E")
        return v 