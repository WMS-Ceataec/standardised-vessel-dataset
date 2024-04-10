using FluentValidation;
using Microsoft.Extensions.DependencyInjection;
using StandardisedVesselDataset.Exporters.Formats.CSV;
using StandardisedVesselDataset.Exporters.Formats.Json;
using StandardisedVesselDataset.Exporters.Formats.XML;
using StandardisedVesselDataset.Models;
using StandardisedVesselDataset.Validators;
using Svd = StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace StandardisedVesselDataset.Extensions;

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
    /// Register custom validator for <see cref="StandardisedVesselDataset"/>
    /// </summary>
    /// <typeparam name="TValidator">The extended custom validator.</typeparam>
    /// <param name="services">The service collection</param>
    /// <returns></returns>
    public static IServiceCollection AddCustomValidator<TValidator>(this IServiceCollection services)
      where TValidator : class, IValidator<Models.StandardisedVesselDataset>
    {
        services.AddScoped<IValidator<Models.StandardisedVesselDataset>, TValidator>();
        return services;
    }

    private static IServiceCollection AddValidators(this IServiceCollection services)
    {
        services.AddScoped<IValidator<Models.StandardisedVesselDataset>, StandardisedVesselDatasetValidator>();
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
