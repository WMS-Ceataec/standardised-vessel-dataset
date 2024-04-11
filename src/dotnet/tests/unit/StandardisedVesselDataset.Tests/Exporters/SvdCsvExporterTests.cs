using StandardisedVesselDataset.Exporters;
using StandardisedVesselDataset.Exporters.Formats.CSV;
using CsvHelper;
using System.Globalization;
using System.Text;
using StandardisedVesselDataset.Exporters.Formats.CSV.Converters;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Tests.Exporters;

public class SvdCsvExporterTests : BaseExporterTests
{
    protected override ISvdExporter Exporter => new SvdCsvExporter(Validator);

    protected override Svd DeserializeContent(byte[] svd)
    {

        using var memoryStream = new MemoryStream(svd);
        using var reader = new StreamReader(memoryStream, Encoding.UTF8);
        using var csvReader = new CsvReader(reader, new CsvHelper.Configuration.CsvConfiguration(CultureInfo.InvariantCulture));
 
        csvReader.Context.TypeConverterCache.AddConverter<string>(new NullableStringConverter());
        csvReader.Context.TypeConverterCache.AddConverter<DateTime>(new UtcDatetimeConverter());
        csvReader.Read();
        return csvReader.GetRecord<Svd>();
    }
}