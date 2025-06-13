"""Electricity consumption model for vessel data."""

from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class ElectricityConsumption(BaseVesselModel):
    """Represents the "Electricity Consumption" section of the SVD."""

    # Basic electricity consumption
    boiler_electricity_consumption: Optional[float] = Field(
        None, description="Boiler electricity consumption, measured in kilowatt hours since last reporting."
    )
    generator_production: Optional[float] = Field(
        None, description="The measure of the production of a generator not used for propulsion, in kilowatt hours since last reporting."
    )
    offset_electricity_consumption: Optional[float] = Field(
        None, description="The permitted quantity of electricity consumption during report duration which can be used to offset/correct emissions calculations, measured in kilowatt hours."
    )

    # Power consumption for specific systems
    power_consumption_for_plant: Optional[float] = Field(
        None, description="Power consumption from generator used for re-liquification, related to the plant (cooling of cargo), measured in kilowatt hours since last reporting."
    )
    electrical_for_cargo_cooling: Optional[float] = Field(
        None, description="Electrical power generated for Cargo Cooling, measured in kilowatt-hours."
    )
    electrical_for_discharge_pump: Optional[float] = Field(
        None, description="Electrical power generated for Discharge Pump, measured in kilowatt-hours."
    )
    electrical_for_reefer_containers: Optional[float] = Field(
        None, description="Electrical power generated for Reefer Containers, measured in kilowatt-hours."
    )

    # External power sources
    electrical_from_on_shore_power_supply: Optional[float] = Field(
        None, description="Amount of electrical power received from on-shore power supply when in port, measured in kilowatt-hours."
    )
    electrical_from_zero_emissions_technologies: Optional[float] = Field(
        None, description="Amount of electrical power received from zero emissions technologies (solar panels etc), measured in kilowatt-hours."
    )

    # Fuel type information
    fuel_type_used_for_cargo_cooling: Optional[str] = Field(
        None, description="A code representing the type of fuel used for electrical work generated for cargo cooling."
    )
    fuel_type_used_for_discharge_pump: Optional[str] = Field(
        None, description="A code representing the type of fuel used for electrical work generated for discharge pump."
    )
    fuel_type_used_for_reefer_containers: Optional[str] = Field(
        None, description="A code representing the type of fuel used for electrical work generated for reefer containers."
    )

    # Fuel oil consumption rates
    fuel_oil_consumption_for_cargo_cooling: Optional[float] = Field(
        None, description="A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Cargo Cooling, measured in grams of fuel consumed per kilowatt-hour (g/kWh)."
    )
    fuel_oil_consumption_for_discharge_pump: Optional[float] = Field(
        None, description="A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Discharge Pump, measured in grams of fuel consumed per kilowatt-hour (g/kWh)."
    )
    fuel_oil_consumption_for_reefer_containers: Optional[float] = Field(
        None, description="A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Reefer Containers, measured in grams of fuel consumed per kilowatt-hour (g/kWh)."
    )

    @field_validator(
        "boiler_electricity_consumption",
        "generator_production",
        "offset_electricity_consumption",
        "power_consumption_for_plant",
        "electrical_for_cargo_cooling",
        "electrical_for_discharge_pump",
        "electrical_for_reefer_containers",
        "electrical_from_on_shore_power_supply",
        "electrical_from_zero_emissions_technologies",
        "fuel_oil_consumption_for_cargo_cooling",
        "fuel_oil_consumption_for_discharge_pump",
        "fuel_oil_consumption_for_reefer_containers",
    )
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v 