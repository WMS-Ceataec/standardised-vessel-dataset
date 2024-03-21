# StandardisedVesselDataSet library

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE)
[![NuGet](https://img.shields.io/nuget/v/SmartMaritimeDataLibrary.svg)](https://www.nuget.org/packages/Ceataec.StandardisedVesselDataSet)

## Overview

This is an open-source .NET Core library designed to wrap around and provide additional functionality related to the [StandardisedVesselDataSet for Noon Reports provided by Smart Maritime Industry](https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/). The primary purpose of this library is to typify the model, validate and export data to various output formats such as XML, CSV, or JSON.

## Features

- Typified StandardisedVesselDataset (SVD) models
- Validation of SVD input data
- Export of data to XML, CSV, or JSON formats

## Installation

You can install the package via NuGet Package Manager Console:

```shell
Install-Package StandardisedVesselDataSet
```

Or using .NET Core CLI

```shell
dotnet add package StandardisedVesselDataSet
```

## Usage
To get started with the library, you can use the following code snippet:

```c#

using Ceataec.StandardisedVesselDataset.Exporters.Formats.XML;
using Ceataec.StandardisedVesselDataset.Extensions;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using SimpleExporter;
using System.Xml.Serialization;

var builder = Host.CreateApplicationBuilder(args);

//register package DI (Dependency injection) services
builder.Services.AddSvd();

using IHost host = builder.Build();

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
    var filePath = ""; //file path
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
            IMO = vesselData.VesselImo,
            VesselName = vesselData.VesselName,
            Time = vesselData.ReportDate,
        },
        PortAndRouteInformation = new PortAndRouteInformation()
        {
            DeparturePort = vesselData.DeparturePort,
            DepartureTime = vesselData.DepartureTime,
            DestinationPort = vesselData.DestinationPort,
            DistanceToDestinationPortKM = vesselData.DistanceToDestinationPortKM
        }
    };
}

```
## Validation

As the StandardisedVesselDataSet (SVD) model is still in its early phases, and adoption by companies may vary, we aim to be flexible with validation to accommodate different use cases. We understand that the sector might have unique requirements or variations in their data.

To provide a customizable solution, we have included an extensibility point for validation. You can easily extend our default validator and add your own rules that align with your specific needs. Below is an example of how you can create and register a custom validator:

Create your custom validator:

```csharp
using Ceataec.StandardisedVesselDataset.Validators;

namespace Ceataec.StandardisedVesselDataset.Example
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

## Supported Output formats
- XML
- CSV
- JSON

## Contributing
We welcome contributions! If you'd like to contribute to this library, please check out our contribution [guidelines](./CONTRIBUTING.md).

## License
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## Acknowledgments
The foundational design of the Standardised Vessel DataSet (SVD) model was crafted by Smart Maritime Industry. Ceateac, a company within the Wilhelmsen Group, has developed this library as an initial version. We anticipate continuous iterative development and improvement to enhance its functionality and features.

## Contact

For any questions or feedback, feel free to join us at [Slack - Ceataec Community](https://join.slack.com/t/ceataeccommunity/shared_invite/zt-2d9ofsmqd-z0Eg8110zM91kmdUCsM31Q).