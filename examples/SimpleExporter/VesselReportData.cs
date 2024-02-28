namespace SimpleExporter;

public class VesselReportData
{
    public string VesselImo { get; init; }
    public string VesselName { get; init; }
    public DateTime ReportDate { get; init; }
    public string DeparturePort { get; init; }
    public DateTime DepartureTime { get; init; }
    public string DestinationPort { get; init; }
    public double DistanceToDestinationPortKm { get; init; }
}