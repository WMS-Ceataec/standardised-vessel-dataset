using CsvHelper;
using CsvHelper.Configuration;
using CsvHelper.TypeConversion;

namespace Ceataec.StandardisedVesselDataset.Exporters.Formats.CSV.Converters;

public class NullableStringConverter : DefaultTypeConverter
{
    public override object ConvertFromString(string text, IReaderRow row, MemberMapData memberMapData)
    {
        return string.IsNullOrEmpty(text) ? null : text;
    }
}