﻿namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the "General" section of SVD
/// </summary>
public class GeneralInformation
{
    /// <summary>
    /// A code representing the event which triggers the reporting (e.g. Noon Report, Arrival, Departure). Event may vary according to contract.
    /// </summary>
    public string EventType { get; init; }

    /// <summary>
    /// A code representing the type of operation being undertaken for the duration of the report (e.g. sailing, in port loading, at anchor).
    /// </summary>
    public string OperationType { get; init; }

    /// <summary>
    /// Additional description of the operation.
    /// </summary>
    public string OperationDescription { get; init; }

    /// <summary>
    /// A code indicating the type of performance report.
    /// </summary>
    public string PerformanceReportType { get; init; }

    /// <summary>
    /// The duration in hours since previous event report.
    /// </summary>
    public TimeSpan ElapsedTime { get; init; }

    /// <summary>
    /// The latitude (geographical coordinate) of the location of the ship at the time of reporting.
    /// </summary>
    public double ShipLatitude { get; init; }

    /// <summary>
    /// The longitude (geographical coordinate) of the location of the ship at the time of reporting.
    /// </summary>
    public double ShipLongitude { get; init; }

    /// <summary>
    /// The date and time when the reporting event occurred.
    /// </summary>
    public DateTime ShipReportingDate { get; init; }

    /// <summary>
    /// A code representing the nationality of the ship shown on its IMO ship's certificate.
    /// </summary>
    public string ShipFlagState { get; init; }

    /// <summary>
    /// A code representing the port of registry shown on the IMO ship certificate.
    /// </summary>
    public string ShipRegistryPortCode { get; init; }

    /// <summary>
    /// The name and country for the Port of Registry shown on the IMO ship certificate.
    /// </summary>
    public string ShipRegistryPortName { get; init; }

    /// <summary>
    /// The ship’s name shown on the IMO ship’s certificates.
    /// </summary>
    public string ShipName { get; init; }

    /// <summary>
    /// The ship identification number shown on its IMO ship’s certificate.
    /// </summary>
    public string Imo { get; init; }

    /// <summary>
    /// The unique radio identification number (ship station identity).
    /// </summary>
    public string Mmsi { get; init; }

    /// <summary>
    /// The type of the ship.
    /// </summary>
    public string ShipType { get; init; }

    /// <summary>
    /// A code representing the ship type as defined in MARPOL Annex VI.
    /// </summary>
    public string ShipTypeMarpolAnnexVi { get; init; }

    /// <summary>
    /// The count of persons onboard the ship who are passengers as defined by SOLAS.
    /// </summary>
    public int NumberOfPassengers { get; init; }

    /// <summary>
    /// The count of persons actually employed for duties on board during a voyage in the working or service of a ship and included in the crew list.
    /// </summary>
    public int NumberOfCrew { get; init; }

    /// <summary>
    /// An operator-assigned reference code for the ship's voyage.
    /// </summary>
    public string VoyageNumber { get; init; }

    /// <summary>
    /// Remarks from the ship or any other information relevant to the voyage.
    /// </summary>
    public string VoyageRemarks { get; init; }

    /// <summary>
    /// The identifier used to uniquely describe a leg of a voyage. The identifier can be a reference to features in another electronic dataset such as a route plan.
    /// </summary>
    public string VoyageLegIdentifier { get; init; }

    /// <summary>
    /// Remarks from the ship or any other information relevant to the voyage leg.
    /// </summary>
    public string VoyageLegRemarks { get; init; }
}