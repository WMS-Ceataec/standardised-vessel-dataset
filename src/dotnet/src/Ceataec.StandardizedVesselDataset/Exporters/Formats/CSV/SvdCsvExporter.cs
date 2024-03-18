using CsvHelper;
using FluentValidation;
using System.Globalization;
using System.Text;
using Ceataec.StandardizedVesselDataset.Exporters.Formats.CSV.Converters;
using Ceataec.StandardizedVesselDataset.Exporters.Models;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Exporters.Formats.CSV;

internal class SvdCsvExporter(IValidator<Svd> validator) : BaseExporter(validator), ISvdCsvExporter
{
    private const string UtcFormat = "yyyy-MM-ddTHH:mm:ss.fffffffZ";

    protected override Task<StandardizedVesselDatasetContent> InternalExportAsync(Svd svd)
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
           Task.FromResult(new StandardizedVesselDatasetContent(Encoding.UTF8.GetBytes(csvExport.ToString()),
           $"SVD_{svd.General.Imo}_{svd.General.Time:yyyy-MM-dd}.csv"));
    }
}