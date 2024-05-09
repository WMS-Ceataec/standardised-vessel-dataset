namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the "Fresh Water" section of SVD
/// </summary>
public class FreshWater
{
    /// <summary>
    /// Fresh water bunkered on board, measured in metric tons.
    /// </summary>
    public double FreshWaterBunkered { get; init; }

    /// <summary>
    /// Fresh water produced on board by running the fresh water generator, measured in metric tons.
    /// </summary>
    public double FreshWaterProduced { get; init; }

    /// <summary>
    /// Fresh water (drinking water) consumed on board, measured in metric tons.
    /// </summary>
    public double FreshWaterConsumed { get; init; }

    /// <summary>
    /// Technical water (< 15 ppm) produced on board, measured in metric tons.
    /// </summary>
    public double TechnicalWaterProduced { get; init; }

    /// <summary>
    /// Technical water (< 15 ppm) consumed on board, measured in metric tons.
    /// </summary>
    public double TechnicalWaterConsumed { get; init; }

    /// <summary>
    /// Wash water (for exhaust gas cleaning systems) consumed on board, measured in metric tons.
    /// </summary>
    public double WashWaterConsumed { get; init; }

    /// <summary>
    /// Fresh drinking water remaining on board, measured in metric tons.
    /// </summary>
    public double FreshWaterRemaining { get; init; }
}
