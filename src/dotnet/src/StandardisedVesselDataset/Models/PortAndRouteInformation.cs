namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Port and Route Information section of SVD
/// </summary>
public class PortAndRouteInformation
{
    public string DeparturePort { get; set; }
    public DateTime DepartureTime { get; set; }
    public string DestinationPort { get; set; }
    public DateTime Etapbp { get; set; }
    public DateTime EtaBerth { get; set; }
    public DateTime Etavts { get; set; }
    public double DistanceToNextWaypointNm { get; set; }
    public double DistanceToNextWaypointKm { get; set; }
    public double DistanceToDestinationPortNm { get; set; }
    public double DistanceToDestinationPortKm { get; set; }
    public double ProjectedSpeedKn { get; set; }
    public double ProjectedSpeedKmh { get; set; }
    public TimeSpan VoyageTime { get; set; }
}