namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the electricity consumption section of the SVD.
/// </summary>
public class ElectricityConsumption
{
    /// <summary>
    /// Boiler electricity consumption, measured in kilowatt hours since last reporting.
    /// </summary>
    public double BoilerElectricityConsumption { get; init; }

    /// <summary>
    /// Measure of the production of a generator not used for propulsion, in kilowatt hours since last reporting.
    /// </summary>
    public double GeneratorProduction { get; init; }

    /// <summary>
    /// Permitted quantity of electricity consumption during report duration which can be used to offset/correct emissions calculations, measured in kilowatt hours.
    /// </summary>
    public double OffsetElectricityConsumption { get; init; }

    /// <summary>
    /// Power consumption from generator used for re-liquification, related to the plant (cooling of cargo), measured in kilowatt hours since last reporting.
    /// </summary>
    public double PowerConsumptionForPlant { get; init; }
}
