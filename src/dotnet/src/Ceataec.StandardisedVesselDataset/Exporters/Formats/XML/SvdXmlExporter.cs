using System.Xml.Serialization;
using System.Xml;
using Ceataec.StandardisedVesselDataset.Exporters.Models;
using FluentValidation;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Exporters.Formats.XML;


internal class SvdXmlExporter(IValidator<Svd> validator)
    : BaseExporter(validator), ISvdXmlExporter
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
