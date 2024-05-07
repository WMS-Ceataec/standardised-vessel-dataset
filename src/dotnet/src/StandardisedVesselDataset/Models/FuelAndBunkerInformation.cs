namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the Fuel and Bunker Information section of SVD.
/// </summary>
public class FuelAndBunkerInformation
{
    /// <summary>
    /// Code representing the type of bunkered fuel.
    /// </summary>
    public string FuelType { get; init; }

    /// <summary>
    /// Identification number for the Bunker Delivery Note (BDN) associated with the fuel provided.
    /// </summary>
    public string BunkerDeliveryNoteNumber { get; init; }

    /// <summary>
    /// Date and time as given in the BDN, e.g., the time when all fuel has been received.
    /// </summary>
    public DateTime BunkerDeliveryDateTime { get; init; }

    /// <summary>
    /// Amount of fuel received during bunkering, measured in metric tonnes.
    /// </summary>
    public double FuelBunkered { get; init; }

    /// <summary>
    /// Mass of fuel, measured in metric tons (mt).
    /// </summary>
    public double FuelMass { get; init; }

    /// <summary>
    /// Density of fuel at 15 degrees Celsius, measured in metric tons per cubic metre (mt/m3).
    /// </summary>
    public double FuelDensity { get; init; }

    /// <summary>
    /// Sulphur content in fuel, measured in percentage per millimetre (% m/m).
    /// </summary>
    public double FuelSulphurContent { get; init; }

    /// <summary>
    /// Viscosity of fuel, measured in centistokes (cSt).
    /// </summary>
    public double FuelViscosity { get; init; }

    /// <summary>
    /// Water content of fuel, measured in % volume per volume (% V/V).
    /// </summary>
    public double FuelWaterContent { get; init; }

    /// <summary>
    /// Higher heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg).
    /// </summary>
    public double FuelHigherHeatingValue { get; init; }

    /// <summary>
    /// Lower heating value of the fuel (calorific value), measured in megajoules per kilogram (MJ/kg).
    /// </summary>
    public double FuelLowerHeatingValue { get; init; }

    /// <summary>
    /// Information referring to the fuel grade, quality and composition.
    /// </summary>
    public string FuelGrade { get; init; }

    /// <summary>
    /// Code representing the port where the fuel is to be bunkered, according to a bunker delivery note.
    /// </summary>
    public string FuelBunkerPort { get; init; }

    /// <summary>
    /// Name and country of the port where the fuel is to be bunkered, according to a bunker delivery note.
    /// </summary>
    public string FuelBunkerPortName { get; init; }

    /// <summary>
    /// Carbon Dioxide (CO2) emissions, expressed in grams of CO2 per gram of fuel, gCO2/g.
    /// </summary>
    public double FuelCarbonDioxideEmission { get; init; }

    /// <summary>
    /// Total fuel consumed, measured in metric tonnes since last reporting.
    /// </summary>
    public double TotalFuelConsumed { get; init; }

    /// <summary>
    /// Fuel consumed by Main Engine, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByME { get; init; }

    /// <summary>
    /// Fuel consumed by diesel electric propulsion, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByDE { get; init; }

    /// <summary>
    /// Fuel consumed by Diesel Generator, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByDG { get; init; }

    /// <summary>
    /// Fuel consumed by Auxiliary Boiler, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByAuxiliaryBoiler { get; init; }

    /// <summary>
    /// Remaining fuel on board based on Engine Room log entries, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelRemainingOnBoard { get; init; }

    /// <summary>
    /// Amount of sludge remaining onboard, measured in metric tonnes since last reporting.
    /// </summary>
    public double SludgeRemainingOnBoard { get; init; }
}
