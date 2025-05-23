/**
 * Represents the "Speed and Distance" section of SVD.
 */
export type SpeedAndDistance = {
  /**
   * Distance traveled through water measured in nautical miles (includes distance sailed in bad weather or through ice, if any).
   */
  DistanceThroughWater: number;

  /**
   * Distance traveled over ground measured in nautical miles.
   */
  DistanceOverGround: number;

  /**
   * Distance sailed within the time elapsed when navigating through ice, measured in nautical miles.
   */
  DistanceSailedInIce: number;

  /**
   * Remaining sailing distance until next port (over ground), measured in nautical miles.
   */
  DistanceToNextPort: number;

  /**
   * Distance to the next waypoint as per voyage plan, in nautical miles.
   */
  DistanceToNextWaypoint: number;

  /**
   * Total distance, over ground, from port to port, measured in nautical miles.
   */
  TotalDistanceOnSeaPassage: number;

  /**
   * The distance which must be excluded for reporting correction, over ground distance measured in nautical miles.
   */
  DistanceExcluded: number;

  /**
   * Ship's current speed over ground, measured in knots.
   */
  SpeedOverGround: number;

  /**
   * Average speed through water, measured in knots.
   */
  SpeedThroughWater: number;

  /**
   * Average speed of each propeller(s), measured in Revolutions Per Minute (RPM).
   */
  SpeedPropeller: number;

  /**
   * Intended speed for the next 24 hours measured in knots.
   */
  SpeedProjected: number;

  /**
   * Speed specified by the charter party measured in knots.
   */
  SpeedOrder: number;

  /**
   * Difference between the actual distance travelled by a ship and the theoretical distance given by the product of the propeller pitch and the number of revolutions.
   */
  Slip: number;

  /**
   * Ship's current course over ground indicated in the 360 degrees notation from true north.
   */
  CourseOverGround: number;

  /**
   * Direction in which the ship is pointing with respect to true north, expressed in degrees.
   */
  ShipTrueHeading: number;

  /**
   * Maximum ship present static draught in metres and centimetres.
   */
  ShipDraught: string;

  /**
   * Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from forward.
   */
  DraughtForward: number;

  /**
   * Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from aft.
   */
  DraughtAft: number;

  /**
   * Difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the actual draught and the lightweight of the ship.
   */
  ShipActualDeadweightTonnage: number;

  /**
   * The difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the maximum draught and the lightweight of the ship.
   */
  ShipMaximumDeadweight: number;

  /**
   * Indicates whether the ship is laden at the time of reporting (“yes” or “no”).
   */
  LadenIndicator: boolean;

  /**
   * Total physical measurement of ballast water on board including sediments measured in cubic metres (m³).
   */
  TotalBallastWaterOnboard: number;
};