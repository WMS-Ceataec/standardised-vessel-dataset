#pragma once

namespace svd {
namespace models {

/// <summary>
/// Represent the "Cylinder Lube Oil Information" section of SVD
/// </summary>
class CylinderLubeOilInformation
{
private:
    double m_remainingOnBoard;
    double m_feedRate;
    double m_consumption;
    double m_receivedDuringBunkering;

public:
    CylinderLubeOilInformation() = default;

    /// <summary>
    /// Cylinder lube oil remaining on board based on Engine Room log entries, measured in metric tons.
    /// </summary>
    double getRemainingOnBoard() const { return m_remainingOnBoard; }
    void setRemainingOnBoard(double remainingOnBoard) { m_remainingOnBoard = remainingOnBoard; }

    /// <summary>
    /// Rate of feed of lube oil into the cylinder, measured in grams per kilowatt hour (g/kWh).
    /// </summary>
    double getFeedRate() const { return m_feedRate; }
    void setFeedRate(double feedRate) { m_feedRate = feedRate; }

    /// <summary>
    /// Lube oil consumption in grams per hour per unit of output measured in kilowatts of the engine (g/kWh).
    /// </summary>
    double getConsumption() const { return m_consumption; }
    void setConsumption(double consumption) { m_consumption = consumption; }

    /// <summary>
    /// Lube oil received during bunkering, measured in metric tons.
    /// </summary>
    double getReceivedDuringBunkering() const { return m_receivedDuringBunkering; }
    void setReceivedDuringBunkering(double receivedDuringBunkering) { m_receivedDuringBunkering = receivedDuringBunkering; }
};

} // namespace models
} // namespace svd
