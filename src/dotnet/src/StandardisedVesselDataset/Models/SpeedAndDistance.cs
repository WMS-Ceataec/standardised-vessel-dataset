namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Speed and Distance section of SVD
/// </summary>
public class SpeedAndDistance
{
    /// <summary>
    /// Distance traveled through water measured in nautical miles (includes distance sailed in bad weather or through ice, if any).
    /// </summary>
    public double DistanceThroughWater { get; init; }

    /// <summary>
    /// Distance traveled over ground measured in nautical miles.
    /// </summary>
    public double DistanceOverGround { get; init; }

    /// <summary>
    /// Distance sailed within the time elapsed when navigating through ice, measured in nautical miles.
    /// </summary>
    public double DistanceSailedInIce { get; init; }

    /// <summary>
    /// Remaining sailing distance until next port (over ground), measured in nautical miles.
    /// </summary>
    public double DistanceToNextPort { get; init; }

    /// <summary>
    /// Distance to the next waypoint as per voyage plan, in nautical miles.
    /// </summary>
    public double DistanceToNextWaypoint { get; init; }

    /// <summary>
    /// Ship's current speed over ground, measured in knots.
    /// </summary>
    public double SpeedOverGround { get; init; }

    /// <summary>
    /// Average speed through water, measured in knots.
    /// </summary>
    public double SpeedThroughWater { get; init; }

    /// <summary>
    /// Average speed of each propeller(s), measured in Revolutions Per Minute (RPM).
    /// </summary>
    public double SpeedPropeller { get; init; }

    /// <summary>
    /// Intended speed for the next 24 hours measured in knots.
    /// </summary>
    public double SpeedProjected { get; init; }

    /// <summary>
    /// Speed specified by the charter party measured in knots.
    /// </summary>
    public double SpeedOrder { get; init; }

    /// <summary>
    /// Difference between the actual distance travelled by a ship and the theoretical distance given by the product of the propeller pitch and the number of revolutions.
    /// </summary>
    public double Slip { get; init; }

    /// <summary>
    /// Ship's current course over ground indicated in the 360 degrees notation from true north.
    /// </summary>
    public double CourseOverGround { get; init; }

    /// <summary>
    /// Direction in which the ship is pointing with respect to true north, expressed in degrees.
    /// </summary>
    public double ShipHeading { get; init; }

    /// <summary>
    /// Maximum ship present static draught in metres and centimetres.
    /// </summary>
    public string ShipDraught { get; init; }

    /// <summary>
    /// Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from forward.
    /// </summary>
    public double DraughtForward { get; init; }

    /// <summary>
    /// Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from aft.
    /// </summary>
    public double DraughtAft { get; init; }

    /// <summary>
    /// Difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the actual draught and the lightweight of the ship.
    /// </summary>
    public double ShipActualDeadweightTonnage { get; init; }

    /// <summary>
    /// Total physical measurement of ballast water on board including sediments measured in cubic metres (m3).
    /// </summary>
    public double TotalBallastWaterOnboard { get; init; }
}
