"""Port information model for vessel data."""

from typing import Optional

from pydantic import Field

from .base import BaseVesselModel


class PortInformation(BaseVesselModel):
    """Represent the "Port Information" section of SVD."""

    departure_port_code: Optional[str] = Field(
        None, description="The code representing the port from which the ship departs."
    )
    departure_port_name: Optional[str] = Field(
        None, description="The name and country of the port from which the ship departs."
    )
    arrival_port_code: Optional[str] = Field(
        None, description="The code representing the port where the ship arrives."
    )
    arrival_port_name: Optional[str] = Field(
        None, description="The name and country of the port where the ship arrives."
    )
    inbound_port_jurisdiction_code: Optional[str] = Field(
        None,
        description="Reporting jurisdiction covering the arriving port for this voyage. Used to define mandatory reporting requirements related to ship emissions for different voyages.",
    )
    outbound_port_jurisdiction_code: Optional[str] = Field(
        None,
        description="Reporting jurisdiction covering the departure port for this voyage. Used to define mandatory reporting requirements related to ship emissions for different voyages.",
    )
    pilot_boarding_place_name: Optional[str] = Field(
        None,
        description="The name, number, or description used to identify a Pilot boarding place, the location offshore where a pilot may board a vessel in preparation to piloting it through local waters.",
    )
    pilot_boarding_place_location: Optional[str] = Field(
        None, description="The location (geographical coordinates) of the Pilot boarding place."
    )
    berth_name: Optional[str] = Field(
        None,
        description="A name used to identify a berth. A berth is defined as a place, generally named or numbered, where a vessel may moor or anchor.",
    ) 