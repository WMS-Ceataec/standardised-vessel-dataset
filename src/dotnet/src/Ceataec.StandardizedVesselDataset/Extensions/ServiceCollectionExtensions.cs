using Ceataec.StandardizedVesselDataset.Exporters.Formats.CSV;
using Ceataec.StandardizedVesselDataset.Exporters.Formats.Json;
using Ceataec.StandardizedVesselDataset.Exporters.Formats.XML;
using Ceataec.StandardizedVesselDataset.Models;
using Ceataec.StandardizedVesselDataset.Validators;
using FluentValidation;
using Microsoft.Extensions.DependencyInjection;
using Svd = Ceataec.StandardizedVesselDataset.Models.StandardizedVesselDataset;

namespace Ceataec.StandardizedVesselDataset.Extensions;

public static class ServiceCollectionExtensions
{
    /// <summary>
    /// Register SVD related services to container
    /// </summary>
    /// <param name="services">The service collection</param>
    public static IServiceCollection AddSvd(this IServiceCollection services)
    {
        return services.AddValidators().AddExporters();
    }

    /// <summary>
    /// Register custom validator for <see cref="StandardizedVesselDataset"/>
    /// </summary>
    /// <typeparam name="TValidator">The extended custom validator.</typeparam>
    /// <param name="services">The service collection</param>
    /// <returns></returns>
    public static IServiceCollection AddCustomValidator<TValidator>(this IServiceCollection services)
      where TValidator : class, IValidator<Svd>
    {
        services.AddScoped<IValidator<Svd>, TValidator>();
        return services;
    }

    private static IServiceCollection AddValidators(this IServiceCollection services)
    {
        services.AddScoped<IValidator<Svd>, StandardizedVesselDatasetValidator>();
        services.AddScoped<IValidator<General>, GeneralValidator>();

        return services;
    }

    private static IServiceCollection AddExporters(this IServiceCollection services)
    {
        services.AddScoped<ISvdXmlExporter, SvdXmlExporter>();
        services.AddScoped<ISvdJsonExporter, SvdJsonExporter>();
        services.AddScoped<ISvdCsvExporter, SvdCsvExporter>();

        return services;
    }
}
