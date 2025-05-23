namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the "Electricity Consumption" section of the SVD.
/// </summary>
public class ElectricityConsumption
{
    /// <summary>
    /// Boiler electricity consumption, measured in kilowatt hours since last reporting.
    /// </summary>
    public double BoilerElectricityConsumption { get; init; }

    /// <summary>
    /// The measure of the production of a generator not used for propulsion, in kilowatt hours since last reporting.
    /// </summary>
    public double GeneratorProduction { get; init; }

    /// <summary>
    /// The permitted quantity of electricity consumption during report duration which can be used to offset/correct emissions calculations, measured in kilowatt hours.
    /// </summary>
    public double OffsetElectricityConsumption { get; init; }

    /// <summary>
    /// Power consumption from generator used for re-liquification, related to the plant (cooling of cargo), measured in kilowatt hours since last reporting.
    /// </summary>
    public double PowerConsumptionForPlant { get; init; }

    /// <summary>
    /// Electrical power generated for Cargo Cooling, measured in kilowatt-hours.
    /// </summary>
    public double ElectricalForCargoCooling { get; init; }

    /// <summary>
    /// Electrical power generated for Discharge Pump, measured in kilowatt-hours.
    /// </summary>
    public double ElectricalForDischargePump { get; init; }

    /// <summary>
    /// Electrical power generated for Reefer Containers, measured in kilowatt-hours.
    /// </summary>
    public double ElectricalForReeferContainers { get; init; }

    /// <summary>
    /// Amount of electrical power received from on-shore power supply when in port, measured in kilowatt-hours.
    /// </summary>
    public double ElectricalFromOnShorePowerSupply { get; init; }

    /// <summary>
    /// Amount of electrical power received from zero emissions technologies (solar panels etc), measured in kilowatt-hours.
    /// </summary>
    public double ElectricalFromZeroEmissionsTechnologies { get; init; }

    /// <summary>
    /// A code representing the type of fuel used for electrical work generated for cargo cooling.
    /// </summary>
    public string FuelTypeUsedForCargoCooling { get; init; }

    /// <summary>
    /// A code representing the type of fuel used for electrical work generated for discharge pump.
    /// </summary>
    public string FuelTypeUsedForDischargePump { get; init; }

    /// <summary>
    /// A code representing the type of fuel used for electrical work generated for reefer containers.
    /// </summary>
    public string FuelTypeUsedForReeferContainers { get; init; }

    /// <summary>
    /// A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Cargo Cooling, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
    /// </summary>
    public double FuelOilConsumptionForCargoCooling { get; init; }

    /// <summary>
    /// A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Discharge Pump, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
    /// </summary>
    public double FuelOilConsumptionForDischargePump { get; init; }

    /// <summary>
    /// A measure of the specific fuel oil consumption of the systems used for generating the electrical power for the Reefer Containers, measured in grams of fuel consumed per kilowatt-hour (g/kWh).
    /// </summary>
    public double FuelOilConsumptionForReeferContainers { get; init; }
}
