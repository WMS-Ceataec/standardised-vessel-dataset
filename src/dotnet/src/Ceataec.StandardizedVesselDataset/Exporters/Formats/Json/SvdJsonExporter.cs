using FluentValidation;
using System.Text.Json;
using Ceataec.StandardizedVesselDataset.Exporters.Models;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Exporters.Formats.Json;

internal class SvdJsonExporter(IValidator<Svd> validator)
    : BaseExporter(validator), ISvdJsonExporter
{
    private readonly JsonSerializerOptions _options = new() 
    {  
        WriteIndented = true, 
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase
    };

    protected override Task<StandardizedVesselDatasetContent> InternalExportAsync(Svd svd)
    {
        var reportData = JsonSerializer.SerializeToUtf8Bytes(svd, _options);

        return
            Task.FromResult(new StandardizedVesselDatasetContent(reportData, $"SVD_{svd.General.Imo}_{svd.General.Time:yyyy-MM-dd}.json"));
    }
}
