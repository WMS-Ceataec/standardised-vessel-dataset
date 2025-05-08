namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the "Fuel and Bunker Information" section of SVD.
/// </summary>
public class FuelAndBunkerInformation
{
    /// <summary>
    /// A code representing the type of bunkered fuel.
    /// </summary>
    public string FuelType { get; init; }

    /// <summary>
    /// A code representing the trade name of the fuel.
    /// </summary>
    public string FuelTypeTradeName { get; init; }

    /// <summary>
    /// The identification number for the Bunker Delivery Note (BDN) associated with the fuel provided.
    /// </summary>
    public string BunkerDeliveryNoteNumber { get; init; }

    /// <summary>
    /// The date and time as given in the BDN, e.g., the time when all fuel has been received.
    /// </summary>
    public DateTime BunkerDeliveryDateTime { get; init; }

    /// <summary>
    /// Reference number from certification confirming that fuel received complies with GHG intensity limit under FuelEU regulations.
    /// </summary>
    public string FuelProofOfSustainabilityReference { get; init; }

    /// <summary>
    /// The amount of fuel received during bunkering, measured in metric tonnes.
    /// </summary>
    public double FuelBunkered { get; init; }

    /// <summary>
    /// Mass of fuel, measured in metric tonnes.
    /// </summary>
    public double FuelMass { get; init; }

    /// <summary>
    /// Density of fuel at 15°C, measured in metric tons per cubic metre (mt/m3).
    /// </summary>
    public double FuelDensity { get; init; }

    /// <summary>
    /// Sulphur content in fuel, measured in percentage per mass (% m/m).
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
    /// Fuel calorific value reporting scheme code, which may differ depending on the reporting scheme.
    /// </summary>
    public string FuelCalorificValueReportingSchemeCode { get; init; }

    /// <summary>
    /// Lower calorific value (LCV) of fuel, measured in megajoules per kilogram.
    /// </summary>
    public double FuelLowerCalorificValue { get; init; }

    /// <summary>
    /// Information referring to the fuel grade, quality and composition.
    /// </summary>
    public string FuelGrade { get; init; }

    /// <summary>
    /// Fuel GHG intensity (IMO) manually, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).
    /// </summary>
    public double FuelGHGIntensityIMOManual { get; init; }

    /// <summary>
    /// Fuel GHG intensity (IMO) per voyage, measured as grams of CO2 equivalent emitted per megajoule (gCO2eq/MJ).
    /// </summary>
    public double FuelGHGIntensityIMOVoyage { get; init; }

    /// <summary>
    /// Code representing the port where the fuel is to be bunkered, according to a bunker delivery note.
    /// </summary>
    public string FuelBunkerPort { get; init; }

    /// <summary>
    /// Name and country of the port where the fuel is to be bunkered, according to a bunker delivery note.
    /// </summary>
    public string FuelBunkerPortName { get; init; }

    /// <summary>
    /// Carbon Dioxide (CO2) emissions per gram of fuel, measured as grams of CO2 per gram (gCO2/g).
    /// </summary>
    public double FuelCarbonDioxideEmission { get; init; }

    /// <summary>
    /// Total fuel consumed, measured in metric tonnes since last reporting.
    /// </summary>
    public double TotalFuelConsumed { get; init; }

    /// <summary>
    /// Fuel consumed by Main Engine, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByMainEngine { get; init; }

    /// <summary>
    /// Fuel consumed by Diesel Electric Propulsion, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByDieselElectricPropulsion { get; init; }

    /// <summary>
    /// Fuel consumed by Diesel Generator, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByDieselGenerator { get; init; }

    /// <summary>
    /// Fuel consumed by Auxiliary Boiler, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByAuxiliaryBoiler { get; init; }

    /// <summary>
    /// Fuel consumed by Auxiliary Engine, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByAuxiliaryEngine { get; init; }

    /// <summary>
    /// Fuel consumed by Cargo Heating, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByCargoHeating { get; init; }

    /// <summary>
    /// Fuel consumed by Reefer Containers, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByReeferContainers { get; init; }

    /// <summary>
    /// Fuel consumed by Discharge Pump, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByDischargePump { get; init; }

    /// <summary>
    /// Fuel consumed by Other Fuel Consuming Devices, measured in metric tonnes since last reporting.
    /// </summary>
    public double FuelConsumedByOtherDevices { get; init; }

    /// <summary>
    /// Remaining fuel on board based on Engine Room log entries, measured in metric tonnes.
    /// </summary>
    public double FuelRemainingOnBoard { get; init; }

    /// <summary>
    /// Amount of sludge remaining onboard, measured in metric tonnes.
    /// </summary>
    public double SludgeRemainingOnBoard { get; init; }
}

