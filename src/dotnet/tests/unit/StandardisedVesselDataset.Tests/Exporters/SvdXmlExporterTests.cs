using StandardisedVesselDataset.Exporters;
using StandardisedVesselDataset.Exporters.Formats.XML;
using System.Xml.Serialization;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Tests.Exporters;

public class SvdXmlExporterTests : BaseExporterTests
{
    protected override ISvdExporter Exporter => new SvdXmlExporter(Validator);

    protected override Svd DeserializeContent(byte[] svdContent)
    {
        var xmlSerializer = new XmlSerializer(typeof(Svd));
        using var memoryStream = new MemoryStream(svdContent);

        return (Svd)xmlSerializer.Deserialize(memoryStream);
    }
}
