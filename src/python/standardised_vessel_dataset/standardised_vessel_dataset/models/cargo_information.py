"""Cargo information model for the Standardised Vessel Dataset."""

from datetime import datetime
from typing import Optional

from pydantic import BaseModel, Field, field_validator


class CargoInformation(BaseModel):
    """Cargo information model for the Standardised Vessel Dataset."""

    cargo_description: Optional[str] = Field(None, description="Description of the cargo")
    gross_weight: Optional[float] = Field(None, description="Gross weight in metric tons")
    gross_volume: Optional[float] = Field(None, description="Gross volume in cubic meters")
    bill_of_lading_reference: Optional[str] = Field(None, description="Bill of lading reference number")
    bill_of_lading_issued_date: Optional[datetime] = Field(None, description="Date when the bill of lading was issued")
    total_containers_teu: Optional[int] = Field(None, description="Total number of containers in TEU")
    total_full_containers_teu: Optional[int] = Field(None, description="Total number of full containers in TEU")
    total_full_reefer_containers_teu: Optional[int] = Field(None, description="Total number of full reefer containers in TEU")
    reefer_sockets_in_use: Optional[int] = Field(None, description="Number of reefer sockets in use")
    chilled_20ft_reefer_containers: Optional[int] = Field(None, description="Number of chilled 20ft reefer containers")
    chilled_40ft_reefer_containers: Optional[int] = Field(None, description="Number of chilled 40ft reefer containers")
    frozen_20ft_reefer_containers: Optional[int] = Field(None, description="Number of frozen 20ft reefer containers")
    frozen_40ft_reefer_containers: Optional[int] = Field(None, description="Number of frozen 40ft reefer containers")
    total_vehicles_ceu: Optional[int] = Field(None, description="Total number of vehicles in CEU")

    @field_validator("gross_weight", "gross_volume")
    @classmethod
    def validate_non_negative(cls, v: Optional[float]) -> Optional[float]:
        """Validate that values are non-negative."""
        if v is not None and v < 0:
            raise ValueError("Value must be non-negative")
        return v

    @field_validator("bill_of_lading_issued_date")
    @classmethod
    def validate_bill_of_lading_date(cls, v: Optional[datetime]) -> Optional[datetime]:
        """Validate that bill of lading date is not in the future."""
        if v is not None and v > datetime.now():
            raise ValueError("Bill of lading date cannot be in the future")
        return v

    @field_validator("total_full_containers_teu")
    @classmethod
    def validate_full_containers(cls, v: Optional[int], values: dict) -> Optional[int]:
        """Validate that total full containers is not greater than total containers."""
        if v is not None and "total_containers_teu" in values.data and values.data["total_containers_teu"] is not None:
            if v > values.data["total_containers_teu"]:
                raise ValueError("Total full containers cannot be greater than total containers")
        return v

    @field_validator("total_full_reefer_containers_teu")
    @classmethod
    def validate_reefer_containers(cls, v: Optional[int], values: dict) -> Optional[int]:
        """Validate that total full reefer containers is not greater than total full containers."""
        if v is not None and "total_full_containers_teu" in values.data and values.data["total_full_containers_teu"] is not None:
            if v > values.data["total_full_containers_teu"]:
                raise ValueError("Total full reefer containers cannot be greater than total full containers")
        return v

    @field_validator("reefer_sockets_in_use")
    @classmethod
    def validate_reefer_sockets(cls, v: Optional[int], values: dict) -> Optional[int]:
        """Validate that reefer sockets in use is not greater than total full reefer containers."""
        if v is not None and "total_full_reefer_containers_teu" in values.data and values.data["total_full_reefer_containers_teu"] is not None:
            if v > values.data["total_full_reefer_containers_teu"]:
                raise ValueError("Reefer sockets in use cannot be greater than total full reefer containers")
        return v 