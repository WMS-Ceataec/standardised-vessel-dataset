/**
 * Represents the Port and Route Information section of SVD.
 */
export type PortAndRouteInformation = {
    DeparturePort: string
    DepartureTime: Date
    DestinationPort: string
    Etapbp: Date
    EtaBerth: Date
    Etavts: Date
    DistanceToNextWaypointNm: number
    DistanceToNextWaypointKm: number
    DistanceToDestinationPortNm: number
    DistanceToDestinationPortKm: number
    ProjectedSpeedKn: number
    ProjectedSpeedKmh: number
    VoyageTimeMs: number
}
