namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the "Cylinder Lube Oil Information" section of SVD
/// </summary>
public class CylinderLubeOilInformation
{
    /// <summary>
    /// Cylinder lube oil remaining on board based on Engine Room log entries, measured in metric tons.
    /// </summary>
    public double RemainingOnBoard { get; init; }

    /// <summary>
    /// Rate of feed of lube oil into the cylinder, measured in grams per kilowatt hour (g/kWh).
    /// </summary>
    public double FeedRate { get; init; }

    /// <summary>
    /// Lube oil consumption in grams per hour per unit of output measured in kilowatts of the engine (g/kWh).
    /// </summary>
    public double Consumption { get; init; }

    /// <summary>
    /// Lube oil received during bunkering, measured in metric tons.
    /// </summary>
    public double ReceivedDuringBunkering { get; init; }
}
