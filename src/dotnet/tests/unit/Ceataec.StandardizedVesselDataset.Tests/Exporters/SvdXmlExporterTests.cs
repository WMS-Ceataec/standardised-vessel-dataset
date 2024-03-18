using Ceataec.StandardizedVesselDataset.Exporters;
using Ceataec.StandardizedVesselDataset.Exporters.Formats.XML;
using System.Xml.Serialization;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Tests.Exporters;

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
