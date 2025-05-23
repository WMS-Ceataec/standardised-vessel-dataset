using StandardisedVesselDataset.Exporters.Formats.XML;
using StandardisedVesselDataset.Extensions;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using SimpleExporter;
using System.Xml.Serialization;
using StandardisedVesselDataset.Models;

var builder = Host.CreateApplicationBuilder(args);

//register package DI (Dependency injection) services
builder.Services.AddSvd();
builder.Services.AddCustomValidator<ExtendedStandardisedVesselDatasetValidator>();

using var host = builder.Build();

await ExportAsync(host.Services.GetRequiredService<ISvdXmlExporter>());


await host.RunAsync();


static async Task ExportAsync(ISvdXmlExporter exporter)
{
    //Load Data
    var vesselReportData = LoadVesselReportData();

    //Map
    var svdData = MapToSvd(vesselReportData);
    
    //Export
    var reportContent = await exporter.ExportAsync(svdData);

    Console.WriteLine($"Writing file to: {reportContent.FileName}");
    await File.WriteAllBytesAsync(reportContent.FileName, reportContent.Content);
}

static VesselReportData LoadVesselReportData()
{
    var filePath = Path.Combine("Data", "report.xml");
    using var reader = new StreamReader(filePath);
    var serializer = new XmlSerializer(typeof(VesselReportData));
    return (VesselReportData)serializer.Deserialize(reader);
}

static StandardisedVesselDataset.Models.StandardisedVesselDataset MapToSvd(VesselReportData vesselData)
{
    return new StandardisedVesselDataset.Models.StandardisedVesselDataset()
    {
        General = new GeneralInformation()
        {
            Imo = vesselData.VesselImo,
            ShipName = vesselData.VesselName,
            ShipReportingDate = vesselData.ReportDate,
        },
        PortAndRoute = new PortInformation()
        {
            DeparturePortCode = vesselData.DeparturePort,
            DeparturePortName = vesselData.DeparturePortDescription,
            ArrivalPortCode = vesselData.DestinationPort,
            ArrivalPortName = vesselData.DestinationPortDescription
        }
    };
}