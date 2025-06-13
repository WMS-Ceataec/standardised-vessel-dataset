"""Fuel and bunker information model for vessel data."""

from datetime import datetime
from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class FuelAndBunkerInformation(BaseVesselModel):
    """Represents the "Fuel and Bunker Information" section of SVD."""

    # Fuel identification
    fuel_type: Optional[str] = Field(None, description="A code representing the type of bunkered fuel.")
    fuel_type_trade_name: Optional[str] = Field(None, description="A code representing the trade name of the fuel.")
    bunker_delivery_note_number: Optional[str] = Field(
        None, description="The identification number for the Bunker Delivery Note (BDN) associated with the fuel provided."
    )
    bunker_delivery_datetime: Optional[datetime] = Field(
        None, description="The date and time as given in the BDN, e.g., the time when all fuel has been received."
    )
    fuel_proof_of_sustainability_reference: Optional[str] = Field(
        None,
        description="Reference number from certification confirming that fuel received complies with GHG intensity limit under FuelEU regulations.",
    )

    # Fuel properties
    fuel_bunkered: Optional[float] = Field(
        None, description="The amount of fuel received during bunkering, measured in metric tonnes."
    )
    fuel_mass: Optional[float] = Field(None, description="Mass of fuel, measured in metric tonnes.")
    fuel_density: Optional[float] = Field(
        None, description="Density of fuel at 15°C, measured in metric tons per cubic metre (mt/m3)."
    )
    fuel_sulphur_content: Optional[float] = Field(
        None, description="Sulphur content in fuel, measured in percentage per mass (% m/m)."
    )
    fuel_viscosity: Optional[float] = Field(None, description="Viscosity of fuel, measured in centistokes (cSt).")
    fuel_water_content: Optional[float] = Field(
        None, description="Water content of fuel, measured in % volume per volume (% V/V)."
    )
    fuel_higher_heating_value: Optional[float] = Field(
        None, description="Higher heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg)."
    )
    fuel_lower_heating_value: Optional[float] = Field(
        None, description="Lower heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg)."
    )
    fuel_calorific_value_reporting_scheme_code: Optional[str] = Field(
        None, description="Fuel calorific value reporting scheme code, which may differ depending on the reporting scheme."
    )
    fuel_lower_calorific_value: Optional[float] = Field(
        None, description="Lower calorific value (LCV) of fuel, measured in megajoules per kilogram."
    )
    fuel_grade: Optional[str] = Field(None, description="Information referring to the fuel grade, quality and composition.")

    # GHG and emissions
    fuel_ghg_intensity_imo_manual: Optional[float] = Field(
        None,
        description="Fuel GHG intensity (IMO) manually, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).",
    )
    fuel_ghg_intensity_imo_voyage: Optional[float] = Field(
        None,
        description="Fuel GHG intensity (IMO) per voyage, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).",
    )
    fuel_carbon_dioxide_emission: Optional[float] = Field(
        None, description="Carbon Dioxide (CO2) emissions per gram of fuel, measured as grams of CO2 per gram (gCO2/g)."
    )

    # Bunker location
    fuel_bunker_port: Optional[str] = Field(
        None, description="Code representing the port where the fuel is to be bunkered, according to a bunker delivery note."
    )
    fuel_bunker_port_name: Optional[str] = Field(
        None, description="Name and country of the port where the fuel is to be bunkered, according to a bunker delivery note."
    )

    # Fuel consumption
    total_fuel_consumed: Optional[float] = Field(
        None, description="Total fuel consumed, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_main_engine: Optional[float] = Field(
        None, description="Fuel consumed by Main Engine, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_diesel_electric_propulsion: Optional[float] = Field(
        None, description="Fuel consumed by Diesel Electric Propulsion, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_diesel_generator: Optional[float] = Field(
        None, description="Fuel consumed by Diesel Generator, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_auxiliary_boiler: Optional[float] = Field(
        None, description="Fuel consumed by Auxiliary Boiler, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_auxiliary_engine: Optional[float] = Field(
        None, description="Fuel consumed by Auxiliary Engine, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_cargo_heating: Optional[float] = Field(
        None, description="Fuel consumed by Cargo Heating, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_reefer_containers: Optional[float] = Field(
        None, description="Fuel consumed by Reefer Containers, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_discharge_pump: Optional[float] = Field(
        None, description="Fuel consumed by Discharge Pump, measured in metric tonnes since last reporting."
    )
    fuel_consumed_by_other_devices: Optional[float] = Field(
        None, description="Fuel consumed by Other Fuel Consuming Devices, measured in metric tonnes since last reporting."
    )

    # Remaining quantities
    fuel_remaining_on_board: Optional[float] = Field(
        None, description="Remaining fuel on board based on Engine Room log entries, measured in metric tonnes."
    )
    sludge_remaining_on_board: Optional[float] = Field(
        None, description="Amount of sludge remaining onboard, measured in metric tonnes."
    )

    @field_validator(
        "fuel_bunkered",
        "fuel_mass",
        "fuel_density",
        "fuel_sulphur_content",
        "fuel_viscosity",
        "fuel_water_content",
        "fuel_higher_heating_value",
        "fuel_lower_heating_value",
        "fuel_lower_calorific_value",
        "fuel_ghg_intensity_imo_manual",
        "fuel_ghg_intensity_imo_voyage",
        "fuel_carbon_dioxide_emission",
        "total_fuel_consumed",
        "fuel_consumed_by_main_engine",
        "fuel_consumed_by_diesel_electric_propulsion",
        "fuel_consumed_by_diesel_generator",
        "fuel_consumed_by_auxiliary_boiler",
        "fuel_consumed_by_auxiliary_engine",
        "fuel_consumed_by_cargo_heating",
        "fuel_consumed_by_reefer_containers",
        "fuel_consumed_by_discharge_pump",
        "fuel_consumed_by_other_devices",
        "fuel_remaining_on_board",
        "sludge_remaining_on_board",
    )
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v

    @field_validator("fuel_sulphur_content", "fuel_water_content")
    @classmethod
    def validate_percentage(cls, v: Optional[float]) -> Optional[float]:
        """Validate that percentage values are between 0 and 100."""
        if v is not None and not 0 <= v <= 100:
            raise ValueError("Percentage must be between 0 and 100")
        return v 