using System.Xml.Serialization;
using System.Xml;
using Ceataec.StandardizedVesselDataset.Exporters.Models;
using FluentValidation;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Exporters.Formats.XML;


internal class SvdXmlExporter(IValidator<Svd> validator)
    : BaseExporter(validator), ISvdXmlExporter
{
    protected override Task<StandardizedVesselDatasetContent> InternalExportAsync(Svd svd)
    {
        var xmlSerializer = new XmlSerializer(typeof(Svd));

        using var memoryStream = new MemoryStream();
        using (var xmlWriter = XmlWriter.Create(memoryStream, new XmlWriterSettings { Indent = true }))
        {
            xmlSerializer.Serialize(xmlWriter, svd);
        }

        return
            Task.FromResult(new StandardizedVesselDatasetContent(memoryStream.ToArray(), $"SVD_{svd.General.Imo}_{svd.General.Time:yyyy-MM-dd}.xml"));
    }
}
