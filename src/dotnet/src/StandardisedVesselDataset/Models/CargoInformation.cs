namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the "Cargo Information" section of the SVD.
/// </summary>
public class CargoInformation
{
    /// <summary>
    /// A description of the referenced packaged cargo.
    /// </summary>
    public string CargoDescription { get; init; }

    /// <summary>
    /// The combined weight or mass of the referenced packaged cargo and its packaging from the shipping data, in kilograms (kg).
    /// </summary>
    public double GrossWeight { get; init; }

    /// <summary>
    /// A measure of the gross volume, normally calculated by multiplying the maximum length, width, and height of the cargo item.
    /// </summary>
    public double GrossVolume { get; init; }

    /// <summary>
    /// A reference number issued on the bill of lading.
    /// </summary>
    public string BillOfLadingReference { get; init; }

    /// <summary>
    /// The date when the bill of lading is issued.
    /// </summary>
    public DateTime BillOfLadingIssuedDate { get; init; }

    /// <summary>
    /// The total number of containers onboard (full and empty), measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    public int TotalContainersTEU { get; init; }

    /// <summary>
    /// The total number of full containers onboard, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    public int TotalFullContainersTEU { get; init; }

    /// <summary>
    /// The total number of full reefer containers onboard in use, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    public int TotalFullReeferContainersTEU { get; init; }

    /// <summary>
    /// The total number of reefer power sockets in use during the voyage.
    /// </summary>
    public int ReeferSocketsInUse { get; init; }

    /// <summary>
    /// The total count of 20-foot containers onboard that are filled with chilled or refrigerated goods.
    /// </summary>
    public int Chilled20FtReeferContainers { get; init; }

    /// <summary>
    /// The total count of 40-foot containers onboard that are filled with chilled or refrigerated goods.
    /// </summary>
    public int Chilled40FtReeferContainers { get; init; }

    /// <summary>
    /// The total count of 20-foot containers onboard that are filled with frozen goods.
    /// </summary>
    public int Frozen20FtReeferContainers { get; init; }

    /// <summary>
    /// The total count of 40-foot containers onboard that are filled with frozen goods.
    /// </summary>
    public int Frozen40FtReeferContainers { get; init; }

    /// <summary>
    /// The total number of vehicles onboard, measured in CEU (Car Equivalent Unit).
    /// </summary>
    public int TotalVehiclesCEU { get; init; }
}