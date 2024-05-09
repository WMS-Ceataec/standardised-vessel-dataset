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
     * Duration of the time period covered by the report, typically the same as number of hours since previous event report.
     */
    ElapsedTime: number;

    /**
     * The latitude (geographical coordinate) of the location of the ship at time of reporting.
     */
    ShipLatitude: number;

    /**
     * The longitude (geographical coordinate) of the location of the ship at time of reporting.
     */
    ShipLongitude: number;

    /**
     * The date and time when the reporting event occurred.
     */
    ShipReportingDate: Date;

    /**
     * The ship’s name shown on the IMO ship’s certificates.
     */
    ShipName: string;

    /**
     * The unique ship identification number shown on its IMO ship’s certificate.
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