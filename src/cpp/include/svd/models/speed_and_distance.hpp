#pragma once

#include <string>

namespace svd {
namespace models {

/// <summary>
/// Represent the "Speed and Distance" section of SVD
/// </summary>
class SpeedAndDistance 
{
private:
    double m_distanceThroughWater;
    double m_distanceOverGround;
    double m_distanceSailedInIce;
    double m_distanceToNextPort;
    double m_distanceToNextWaypoint;
    double m_totalDistanceOnSeaPassage;
    double m_distanceExcluded;
    double m_speedOverGround;
    double m_speedThroughWater;
    double m_speedPropeller;
    double m_speedProjected;
    double m_speedOrder;
    double m_slip;
    double m_courseOverGround;
    double m_shipTrueHeading;
    std::string m_shipDraught;
    double m_draughtForward;
    double m_draughtAft;
    double m_shipActualDeadweightTonnage;
    double m_shipMaximumDeadweight;
    bool m_ladenIndicator;
    double m_totalBallastWaterOnboard;

public:
    SpeedAndDistance() = default;    /// <summary>
    /// Distance traveled through water measured in nautical miles (includes distance sailed in bad weather or through ice, if any).
    /// </summary>
    double getDistanceThroughWater() const { return m_distanceThroughWater; }
    void setDistanceThroughWater(double distanceThroughWater) { m_distanceThroughWater = distanceThroughWater; }

    /// <summary>
    /// Distance traveled over ground measured in nautical miles.
    /// </summary>
    double getDistanceOverGround() const { return m_distanceOverGround; }
    void setDistanceOverGround(double distanceOverGround) { m_distanceOverGround = distanceOverGround; }

    /// <summary>
    /// Distance sailed within the time elapsed when navigating through ice, measured in nautical miles.
    /// </summary>
    double getDistanceSailedInIce() const { return m_distanceSailedInIce; }
    void setDistanceSailedInIce(double distanceSailedInIce) { m_distanceSailedInIce = distanceSailedInIce; }

    /// <summary>
    /// Remaining sailing distance until next port (over ground), measured in nautical miles.
    /// </summary>
    double getDistanceToNextPort() const { return m_distanceToNextPort; }
    void setDistanceToNextPort(double distanceToNextPort) { m_distanceToNextPort = distanceToNextPort; }

    /// <summary>
    /// Distance to the next waypoint as per voyage plan, in nautical miles.
    /// </summary>
    double getDistanceToNextWaypoint() const { return m_distanceToNextWaypoint; }
    void setDistanceToNextWaypoint(double distanceToNextWaypoint) { m_distanceToNextWaypoint = distanceToNextWaypoint; }

    /// <summary>
    /// Total distance, over ground, from port to port, measured in nautical miles.
    /// </summary>
    double getTotalDistanceOnSeaPassage() const { return m_totalDistanceOnSeaPassage; }
    void setTotalDistanceOnSeaPassage(double totalDistanceOnSeaPassage) { m_totalDistanceOnSeaPassage = totalDistanceOnSeaPassage; }

    /// <summary>
    /// The distance which must be excluded for reporting correction, over ground distance measured in nautical miles.
    /// </summary>
    double getDistanceExcluded() const { return m_distanceExcluded; }
    void setDistanceExcluded(double distanceExcluded) { m_distanceExcluded = distanceExcluded; }    /// <summary>
    /// Ship's current speed over ground, measured in knots.
    /// </summary>
    double getSpeedOverGround() const { return m_speedOverGround; }
    void setSpeedOverGround(double speedOverGround) { m_speedOverGround = speedOverGround; }

    /// <summary>
    /// Average speed through water, measured in knots.
    /// </summary>
    double getSpeedThroughWater() const { return m_speedThroughWater; }
    void setSpeedThroughWater(double speedThroughWater) { m_speedThroughWater = speedThroughWater; }

    /// <summary>
    /// Average speed of each propeller(s), measured in Revolutions Per Minute (RPM).
    /// </summary>
    double getSpeedPropeller() const { return m_speedPropeller; }
    void setSpeedPropeller(double speedPropeller) { m_speedPropeller = speedPropeller; }

    /// <summary>
    /// Intended speed for the next 24 hours measured in knots.
    /// </summary>
    double getSpeedProjected() const { return m_speedProjected; }
    void setSpeedProjected(double speedProjected) { m_speedProjected = speedProjected; }

    /// <summary>
    /// Speed specified by the charter party measured in knots.
    /// </summary>
    double getSpeedOrder() const { return m_speedOrder; }
    void setSpeedOrder(double speedOrder) { m_speedOrder = speedOrder; }

    /// <summary>
    /// Difference between the actual distance travelled by a ship and the theoretical distance given by the product of the propeller pitch and the number of revolutions.
    /// </summary>
    double getSlip() const { return m_slip; }
    void setSlip(double slip) { m_slip = slip; }

    /// <summary>
    /// Ship's current course over ground indicated in the 360 degrees notation from true north.
    /// </summary>
    double getCourseOverGround() const { return m_courseOverGround; }
    void setCourseOverGround(double courseOverGround) { m_courseOverGround = courseOverGround; }

    /// <summary>
    /// Direction in which the ship is pointing with respect to true north, expressed in degrees.
    /// </summary>
    double getShipTrueHeading() const { return m_shipTrueHeading; }
    void setShipTrueHeading(double shipTrueHeading) { m_shipTrueHeading = shipTrueHeading; }    /// <summary>
    /// Maximum ship present static draught in metres and centimetres.
    /// </summary>
    const std::string& getShipDraught() const { return m_shipDraught; }
    void setShipDraught(const std::string& shipDraught) { m_shipDraught = shipDraught; }

    /// <summary>
    /// Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from forward.
    /// </summary>
    double getDraughtForward() const { return m_draughtForward; }
    void setDraughtForward(double draughtForward) { m_draughtForward = draughtForward; }

    /// <summary>
    /// Vertical distance in metres between the waterline and the bottom of the hull, with the thickness of the hull included from aft.
    /// </summary>
    double getDraughtAft() const { return m_draughtAft; }
    void setDraughtAft(double draughtAft) { m_draughtAft = draughtAft; }

    /// <summary>
    /// Difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the actual draught and the lightweight of the ship.
    /// </summary>
    double getShipActualDeadweightTonnage() const { return m_shipActualDeadweightTonnage; }
    void setShipActualDeadweightTonnage(double shipActualDeadweightTonnage) { m_shipActualDeadweightTonnage = shipActualDeadweightTonnage; }

    /// <summary>
    /// The difference in tonnes between the displacement of a ship in water of a specific gravity of 1.025 at the maximum draught and the lightweight of the ship.
    /// </summary>
    double getShipMaximumDeadweight() const { return m_shipMaximumDeadweight; }
    void setShipMaximumDeadweight(double shipMaximumDeadweight) { m_shipMaximumDeadweight = shipMaximumDeadweight; }

    /// <summary>
    /// Indicates whether the ship is laden at the time of reporting ("yes" or "no").
    /// </summary>
    bool getLadenIndicator() const { return m_ladenIndicator; }
    void setLadenIndicator(bool ladenIndicator) { m_ladenIndicator = ladenIndicator; }

    /// <summary>
    /// Total physical measurement of ballast water on board including sediments measured in cubic metres (m³).
    /// </summary>
    double getTotalBallastWaterOnboard() const { return m_totalBallastWaterOnboard; }
    void setTotalBallastWaterOnboard(double totalBallastWaterOnboard) { m_totalBallastWaterOnboard = totalBallastWaterOnboard; }
};

} // namespace models
} // namespace svd
