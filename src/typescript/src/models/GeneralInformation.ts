/**
 * Represents the "General Information" section of SVD.
 */
export type GeneralInformation = {
  /**
   * A code representing the event which triggers the reporting (e.g. Noon Report, Arrival, Departure). Event may vary according to contract.
   */
  EventType: string;

  /**
   * A code representing the type of operation being undertaken for the duration of the report (e.g. sailing, in port loading, at anchor).
   */
  OperationType: string;

  /**
   * Additional description of the operation.
   */
  OperationDescription: string;

  /**
   * A code indicating the type of performance report.
   */
  PerformanceReportType: string;

  /**
   * The duration in hours since previous event report.
   */
  ElapsedTime: string; // ISO 8601 duration string (e.g. "PT5H")

  /**
   * The latitude (geographical coordinate) of the location of the ship at the time of reporting.
   */
  ShipLatitude: number;

  /**
   * The longitude (geographical coordinate) of the location of the ship at the time of reporting.
   */
  ShipLongitude: number;

  /**
   * The date and time when the reporting event occurred.
   */
  ShipReportingDate: string; // ISO 8601 format (e.g. "2025-01-01T11:11:11Z")

  /**
   * A code representing the nationality of the ship shown on its IMO ship's certificate.
   */
  ShipFlagState: string;

  /**
   * A code representing the port of registry shown on the IMO ship certificate.
   */
  ShipRegistryPortCode: string;

  /**
   * The name and country for the Port of Registry shown on the IMO ship certificate.
   */
  ShipRegistryPortName: string;

  /**
   * The ship’s name shown on the IMO ship’s certificates.
   */
  ShipName: string;

  /**
   * The ship identification number shown on its IMO ship’s certificate.
   */
  Imo: string;

  /**
   * The unique radio identification number (ship station identity).
   */
  Mmsi: string;

  /**
   * The type of the ship.
   */
  ShipType: string;

  /**
   * A code representing the ship type as defined in MARPOL Annex VI.
   */
  ShipTypeMarpolAnnexVi: string;

  /**
   * The count of persons onboard the ship who are passengers as defined by SOLAS.
   */
  NumberOfPassengers: number;

  /**
   * The count of persons actually employed for duties on board during a voyage in the working or service of a ship and included in the crew list.
   */
  NumberOfCrew: number;

  /**
   * An operator-assigned reference code for the ship's voyage.
   */
  VoyageNumber: string;

  /**
   * Remarks from the ship or any other information relevant to the voyage.
   */
  VoyageRemarks: string;

  /**
   * The identifier used to uniquely describe a leg of a voyage. The identifier can be a reference to features in another electronic dataset such as a route plan.
   */
  VoyageLegIdentifier: string;

  /**
   * Remarks from the ship or any other information relevant to the voyage leg.
   */
  VoyageLegRemarks: string;
};