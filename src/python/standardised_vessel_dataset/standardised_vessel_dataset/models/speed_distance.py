"""Speed and distance model for vessel data."""

from typing import Optional

from pydantic import Field, field_validator

from .base import BaseVesselModel


class SpeedAndDistance(BaseVesselModel):
    """Represent the "Speed and Distance" section of SVD."""

    # Distance measurements
    distance_through_water: Optional[float] = Field(
        None,
        description="Distance traveled through water measured in nautical miles (includes distance sailed in bad weather or through ice, if any).",
    )
    distance_over_ground: Optional[float] = Field(
        None, description="Distance traveled over ground measured in nautical miles."
    )
    distance_sailed_in_ice: Optional[float] = Field(
        None, description="Distance sailed within the time elapsed when navigating through ice, measured in nautical miles."
    )
    distance_to_next_port: Optional[float] = Field(
        None, description="Remaining sailing distance until next port (over ground), measured in nautical miles."
    )
    distance_to_next_waypoint: Optional[float] = Field(
        None, description="Distance to the next waypoint as per voyage plan, in nautical miles."
    )
    total_distance_on_sea_passage: Optional[float] = Field(
        None, description="Total distance, over ground, from port to port, measured in nautical miles."
    )
    distance_excluded: Optional[float] = Field(
        None, description="The distance which must be excluded for reporting correction, over ground distance measured in nautical miles."
    )

    # Speed measurements
    speed_over_ground: Optional[float] = Field(None, description="Ship's current speed over ground, measured in knots.")
    speed_through_water: Optional[float] = Field(None, description="Average speed through water, measured in knots.")
    speed_propeller: Optional[float] = Field(
        None, description="Average speed of each propeller(s), measured in Revolutions Per Minute (RPM)."
    )
    speed_projected: Optional[float] = Field(
        None, description="Intended speed for the next 24 hours measured in knots."
    )
    speed_order: Optional[float] = Field(None, description="Speed specified by the charter party measured in knots.")
    slip: Optional[float] = Field(
        None,
        description="Difference between the actual distance travelled by a ship and the theoretical distance given by the product of the propeller pitch and the number of revolutions.",
    )

    # Course and heading
    course_over_ground: Optional[float] = Field(
        None, description="Ship's current course over ground indicated in the 360 degrees notation from true north."
    )
    ship_true_heading: Optional[float] = Field(
        None, description="Direction in which the ship is pointing with respect to true north, expressed in degrees."
    )

    # Draught and displacement
    ship_draught: Optional[str] = Field(
        None, description="Maximum ship present static draught in metres and centimetres."
    )
    draught_forward: Optional[float] = Field(
        None,
        description="Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from forward.",
    )
    draught_aft: Optional[float] = Field(
        None,
        description="Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from aft.",
    )
    ship_actual_deadweight_tonnage: Optional[float] = Field(
        None,
        description="Difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the actual draught and the lightweight of the ship.",
    )
    ship_maximum_deadweight: Optional[float] = Field(
        None,
        description="The difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the maximum draught and the lightweight of the ship.",
    )

    # Status indicators
    laden_indicator: Optional[bool] = Field(
        None, description='Indicates whether the ship is laden at the time of reporting ("yes" or "no").'
    )
    total_ballast_water_onboard: Optional[float] = Field(
        None, description="Total physical measurement of ballast water on board including sediments measured in cubic metres (m³)."
    )

    @field_validator(
        "distance_through_water",
        "distance_over_ground",
        "distance_sailed_in_ice",
        "distance_to_next_port",
        "distance_to_next_waypoint",
        "total_distance_on_sea_passage",
        "distance_excluded",
        "speed_over_ground",
        "speed_through_water",
        "speed_propeller",
        "speed_projected",
        "speed_order",
        "slip",
        "total_ballast_water_onboard",
    )
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v

    @field_validator("course_over_ground", "ship_true_heading")
    @classmethod
    def validate_degrees(cls, v: Optional[float]) -> Optional[float]:
        """Validate that angle values are between 0 and 360 degrees."""
        if v is not None and not 0 <= v <= 360:
            raise ValueError("Angle must be between 0 and 360 degrees")
        return v

    @field_validator("draught_forward", "draught_aft")
    @classmethod
    def validate_draught(cls, v: Optional[float]) -> Optional[float]:
        """Validate that draught values are positive."""
        if v is not None and v <= 0:
            raise ValueError("Draught must be positive")
        return v

    @field_validator("ship_actual_deadweight_tonnage", "ship_maximum_deadweight")
    @classmethod
    def validate_deadweight(cls, v: Optional[float]) -> Optional[float]:
        """Validate that deadweight values are positive."""
        if v is not None and v <= 0:
            raise ValueError("Deadweight must be positive")
        return v 