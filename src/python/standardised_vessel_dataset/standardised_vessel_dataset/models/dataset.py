"""Main dataset model for the Standardised Vessel Dataset."""

from datetime import datetime
from typing import Optional

import pandas as pd
from pydantic import BaseModel, Field

from .arrival_times import ArrivalTimes
from .cargo_information import CargoInformation
from .cylinder_lube_oil import CylinderLubeOilInformation
from .deviation import DeviationFromPlanned
from .electricity import ElectricityConsumption
from .emissions import Emissions
from .fresh_water import FreshWater
from .fuel_bunker import FuelAndBunkerInformation
from .general import GeneralInformation
from .port import PortInformation
from .speed_distance import SpeedAndDistance
from .weather import WeatherInformation


class StandardizedVesselDataset(BaseModel):
    """Main dataset model for the Standardised Vessel Dataset."""

    vessel_imo: str = Field(..., description="IMO number of the vessel")
    vessel_name: str = Field(..., description="Name of the vessel")
    vessel_type: str = Field(..., description="Type of the vessel")
    reporting_period_start: datetime = Field(..., description="Start of the reporting period")
    reporting_period_end: datetime = Field(..., description="End of the reporting period")
    created_at: datetime = Field(default_factory=datetime.now, description="When the dataset was created")
    updated_at: datetime = Field(default_factory=datetime.now, description="When the dataset was last updated")

    # Vessel information sections
    general_information: Optional[GeneralInformation] = Field(None, description="General vessel information")
    cargo_information: Optional[CargoInformation] = Field(None, description="Cargo information")
    arrival_times: Optional[ArrivalTimes] = Field(None, description="Arrival and departure times")
    port_information: Optional[PortInformation] = Field(None, description="Port information")
    speed_and_distance: Optional[SpeedAndDistance] = Field(None, description="Speed and distance information")
    weather_information: Optional[WeatherInformation] = Field(None, description="Weather information")
    fuel_and_bunker_information: Optional[FuelAndBunkerInformation] = Field(None, description="Fuel and bunker information")
    electricity_consumption: Optional[ElectricityConsumption] = Field(None, description="Electricity consumption information")
    fresh_water: Optional[FreshWater] = Field(None, description="Fresh water information")
    cylinder_lube_oil_information: Optional[CylinderLubeOilInformation] = Field(None, description="Cylinder lube oil information")
    emissions: Optional[Emissions] = Field(None, description="Emissions information")
    deviation_from_planned: Optional[DeviationFromPlanned] = Field(None, description="Deviation from planned route information")

    def to_dataframe(self) -> pd.DataFrame:
        """Convert the dataset to a pandas DataFrame."""
        data = {
            "vessel_imo": [str(self.vessel_imo)],  # Ensure IMO is string
            "vessel_name": [self.vessel_name],
            "vessel_type": [self.vessel_type],
            "reporting_period_start": [self.reporting_period_start],
            "reporting_period_end": [self.reporting_period_end],
            "created_at": [self.created_at],
            "updated_at": [self.updated_at],
        }

        # Add all optional sections if they exist
        for section in [
            "general_information",
            "cargo_information",
            "arrival_times",
            "port_information",
            "speed_and_distance",
            "weather_information",
            "fuel_and_bunker_information",
            "electricity_consumption",
            "fresh_water",
            "cylinder_lube_oil_information",
            "emissions",
            "deviation_from_planned",
        ]:
            section_data = getattr(self, section)
            if section_data:
                data.update(section_data.model_dump())

        return pd.DataFrame(data)

    def to_csv(self, filepath: str) -> None:
        """Export the dataset to a CSV file."""
        df = self.to_dataframe()
        df.to_csv(filepath, index=False)

    @classmethod
    def from_csv(cls, filepath: str) -> "StandardizedVesselDataset":
        """Create a dataset from a CSV file."""
        df = pd.read_csv(filepath)
        data = df.iloc[0].to_dict()
        
        # Convert IMO to string
        if "vessel_imo" in data:
            data["vessel_imo"] = str(data["vessel_imo"])
        
        # Convert datetime strings to datetime objects
        for field in ["reporting_period_start", "reporting_period_end", "created_at", "updated_at"]:
            if field in data and pd.notna(data[field]):
                data[field] = pd.to_datetime(data[field])
        
        return cls.model_validate(data) 