## Installation

You can install the package via NuGet Package Manager Console:

```shell
Install-Package Standardised.Vessel.Dataset
```

Or using .NET Core CLI

```shell
dotnet add package Standardised.Vessel.Dataset
```

## Usage
To get started with the library, you can use the following code snippet:

```c#

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
            DeparturePortDescription = vesselData.DeparturePortDescription,
            ArrivalPortCode = vesselData.DestinationPort,
            ArrivalPortDescription = vesselData.DestinationPortDescription
        }
    };
}
```
## Validation

As the Standardised Vessel DataSet (SVD) model is still in its early phases, and adoption by companies may vary, we aim to be flexible with validation to accommodate different use cases. We understand that the sector might have unique requirements or variations in their data.

To provide a customizable solution, we have included an extensibility point for validation. You can easily extend our default validator and add your own rules that align with your specific needs. Below is an example of how you can create and register a custom validator:

Create your custom validator:

```csharp
using StandardisedVesselDataset.Validators;

namespace StandardisedVesselDataset.Example
{
    internal class ExtendedStandardisedVesselDatasetValidator : StandardisedVesselDatasetValidator
    {
        public ExtendedStandardisedVesselDatasetValidator()
        {
            //extend rules here
        }
    }
}
```
Register the validator into the DI container:

```csharp
//Register
builder.Services.AddSvd();
builder.Services.AddCustomValidator<ExtendedStandardisedVesselDatasetValidator>();
```
