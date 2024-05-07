namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the cargo information section of the SVD.
/// </summary>
public class CargoInformation
{
    /// <summary>
    /// Description of the referenced packaged cargo.
    /// </summary>
    public string CargoDescription { get; init; }

    /// <summary>
    /// Combined weight or mass of the referenced packaged cargo and its packaging from the shipping data, in kilograms (kg).
    /// </summary>
    public double GrossWeight { get; init; }

    /// <summary>
    /// Measure of the gross volume, normally calculated by multiplying the maximum length, width and height of the cargo item.
    /// </summary>
    public double GrossVolume { get; init; }

    /// <summary>
    /// Total number of containers on board, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    public int TotalContainersTEU { get; init; }

    /// <summary>
    /// Total number of full containers on board, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    public int TotalFullContainersTEU { get; init; }

    /// <summary>
    /// Total number of full reefer containers on board in use, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    public int TotalFullReeferContainersTEU { get; init; }

    /// <summary>
    /// Total number of vehicles on board, measured in CEU (Car Equivalent Unit).
    /// </summary>
    public int TotalVehiclesCEU { get; init; }
}
