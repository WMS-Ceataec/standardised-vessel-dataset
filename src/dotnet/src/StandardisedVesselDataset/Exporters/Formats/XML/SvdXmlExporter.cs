using System.Xml.Serialization;
using System.Xml;
using FluentValidation;
using StandardisedVesselDataset.Exporters.Models;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Exporters.Formats.XML;


internal class SvdXmlExporter(IValidator<Svd> validator) : BaseExporter(validator), ISvdXmlExporter
{
    protected override Task<StandardisedVesselDatasetContent> InternalExportAsync(Svd svd)
    {
        var xmlSerializer = new XmlSerializer(typeof(Svd));

        using var memoryStream = new MemoryStream();
        using (var xmlWriter = XmlWriter.Create(memoryStream, new XmlWriterSettings { Indent = true }))
        {
            xmlSerializer.Serialize(xmlWriter, svd);
        }

        return
            Task.FromResult(new StandardisedVesselDatasetContent(memoryStream.ToArray(), $"SVD_{svd.General.Imo}_{svd.General.Time:yyyy-MM-dd}.xml"));
    }
}
