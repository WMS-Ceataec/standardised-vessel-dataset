namespace SimpleExporter;

public class VesselReportData
{
    public string VesselImo { get; init; }
    public string VesselName { get; init; }
    public DateTime ReportDate { get; init; }
    public string DeparturePort { get; init; }
    public string DeparturePortDescription { get; init; }
    public string DestinationPort { get; init; }
    public string DestinationPortDescription { get; init; }
}