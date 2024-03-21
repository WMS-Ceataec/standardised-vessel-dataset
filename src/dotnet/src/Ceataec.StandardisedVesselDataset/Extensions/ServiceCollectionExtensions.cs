using Ceataec.StandardisedVesselDataset.Exporters.Formats.CSV;
using Ceataec.StandardisedVesselDataset.Exporters.Formats.Json;
using Ceataec.StandardisedVesselDataset.Exporters.Formats.XML;
using Ceataec.StandardisedVesselDataset.Models;
using Ceataec.StandardisedVesselDataset.Validators;
using FluentValidation;
using Microsoft.Extensions.DependencyInjection;
using Svd = Ceataec.StandardisedVesselDataset.Models.StandardisedVesselDataset;

namespace Ceataec.StandardisedVesselDataset.Extensions;

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
      where TValidator : class, IValidator<Svd>
    {
        services.AddScoped<IValidator<Svd>, TValidator>();
        return services;
    }

    private static IServiceCollection AddValidators(this IServiceCollection services)
    {
        services.AddScoped<IValidator<Svd>, StandardisedVesselDatasetValidator>();
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
