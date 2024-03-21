using Ceataec.StandardisedVesselDataset.Exporters;
using Ceataec.StandardisedVesselDataset.Exporters.Formats.CSV;
using CsvHelper;
using System.Globalization;
using System.Text;
using Ceataec.StandardisedVesselDataset.Exporters.Formats.CSV.Converters;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Tests.Exporters;

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