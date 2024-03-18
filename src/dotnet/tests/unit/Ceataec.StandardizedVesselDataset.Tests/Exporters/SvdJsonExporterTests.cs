using Ceataec.StandardizedVesselDataset.Exporters;
using Ceataec.StandardizedVesselDataset.Exporters.Formats.Json;
using System.Text;
using System.Text.Json;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Tests.Exporters;

public class SvdJsonExporterTests : BaseExporterTests
{
    protected override ISvdExporter Exporter => new SvdJsonExporter(Validator);

    protected override Svd DeserializeContent(byte[] svdContent)
    {
        return JsonSerializer
            .Deserialize<Svd>(Encoding.UTF8.GetString(svdContent), new JsonSerializerOptions() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase});
    }
}
