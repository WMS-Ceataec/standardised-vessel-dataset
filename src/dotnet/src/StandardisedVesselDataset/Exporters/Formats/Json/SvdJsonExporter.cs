using FluentValidation;
using System.Text.Json;
using StandardisedVesselDataset.Exporters.Models;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Exporters.Formats.Json;

internal class SvdJsonExporter(IValidator<Svd> validator) : BaseExporter(validator), ISvdJsonExporter
{
    private readonly JsonSerializerOptions _options = new() 
    {  
        WriteIndented = true, 
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase
    };

    protected override Task<StandardisedVesselDatasetContent> InternalExportAsync(Svd svd)
    {
        var reportData = JsonSerializer.SerializeToUtf8Bytes(svd, _options);

        return
            Task.FromResult(new StandardisedVesselDatasetContent(reportData, $"SVD_{svd.General.Imo}_{svd.General.Time:yyyy-MM-dd}.json"));
    }
}
