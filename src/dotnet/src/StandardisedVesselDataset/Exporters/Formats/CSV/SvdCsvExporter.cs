using CsvHelper;
using FluentValidation;
using System.Globalization;
using System.Text;
using StandardisedVesselDataset.Exporters.Formats.CSV.Converters;
using StandardisedVesselDataset.Exporters.Models;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Exporters.Formats.CSV;

internal class SvdCsvExporter(IValidator<Svd> validator) : BaseExporter(validator), ISvdCsvExporter
{
    private const string UtcFormat = "yyyy-MM-ddTHH:mm:ss.fffffffZ";

    protected override Task<StandardisedVesselDatasetContent> InternalExportAsync(Svd svd)
    {
        var csvExport = new StringBuilder();
        using (var csvWriter = new CsvWriter(new StringWriter(csvExport), CultureInfo.InvariantCulture))
        {
            csvWriter.Context.TypeConverterOptionsCache.GetOptions<DateTime>().Formats = [UtcFormat];
            csvWriter.Context.TypeConverterCache.AddConverter<string>(new NullableStringConverter());
            csvWriter.Context.TypeConverterCache.AddConverter<string>(new UtcDatetimeConverter());

            csvWriter.WriteRecords([svd]);
        }

        return
           Task.FromResult(new StandardisedVesselDatasetContent(Encoding.UTF8.GetBytes(csvExport.ToString()),
           $"SVD_{svd.General.Imo}_{svd.General.ShipReportingDate:yyyy-MM-dd}.csv"));
    }
}