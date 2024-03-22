// See https://aka.ms/new-console-template for more information

using Ceataec.StandardisedVesselDataset.Exporters.Formats.XML;
using Ceataec.StandardisedVesselDataset.Extensions;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using SimpleExporter;
using System.Xml.Serialization;
using Ceataec.StandardisedVesselDataset.Models;

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
    var vesselReportData = await LoadVesselReportDataAsync();

    //Map
    var svdData = MapToSvd(vesselReportData);
    
    //Export
    var reportContent = await exporter.ExportAsync(svdData);

    Console.WriteLine($"Writing file to: [{reportContent.FileName}]");
    await File.WriteAllBytesAsync(reportContent.FileName, reportContent.Content);
}

static async Task<VesselReportData> LoadVesselReportDataAsync()
{
    var filePath = Path.Combine("Data", "report.xml");
    using var reader = new StreamReader(filePath);
    var serializer = new XmlSerializer(typeof(VesselReportData));
    return (VesselReportData)serializer.Deserialize(reader);
}

static StandardisedVesselDataset MapToSvd(VesselReportData vesselData)
{
    return new StandardisedVesselDataset()
    {
        General = new General()
        {
            Imo = vesselData.VesselImo,
            VesselName = vesselData.VesselName,
            Time = vesselData.ReportDate,
        },
        PortAndRouteInformation = new PortAndRouteInformation()
        {
            DeparturePort = vesselData.DeparturePort,
            DepartureTime = vesselData.DepartureTime,
            DestinationPort = vesselData.DestinationPort,
            DistanceToDestinationPortKm = vesselData.DistanceToDestinationPortKm
        }
    };
}