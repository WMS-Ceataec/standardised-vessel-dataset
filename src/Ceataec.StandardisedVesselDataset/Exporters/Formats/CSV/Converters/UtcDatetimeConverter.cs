using CsvHelper;
using CsvHelper.Configuration;

namespace Ceataec.StandardisedVesselDataset.Exporters.Formats.CSV.Converters;

public class UtcDatetimeConverter : CsvHelper.TypeConversion.DateTimeConverter
{
    public override object ConvertFromString(string text, IReaderRow row, MemberMapData memberMapData)
    {
        return DateTime.TryParse(text, out var parsedDateTime) ? 
            parsedDateTime.ToUniversalTime() : 
            base.ConvertFromString(text, row, memberMapData);
    }
}