#pragma once

namespace svd {
namespace models {

/// <summary>
/// Represent the "Fresh Water" section of SVD
/// </summary>
class FreshWater
{
private:
    double m_freshWaterBunkered;
    double m_freshWaterProduced;
    double m_freshWaterConsumed;
    double m_technicalWaterProduced;
    double m_technicalWaterConsumed;
    double m_washWaterConsumed;
    double m_freshWaterRemaining;

public:
    FreshWater() = default;

    /// <summary>
    /// Fresh water bunkered on board, measured in metric tons.
    /// </summary>
    double getFreshWaterBunkered() const { return m_freshWaterBunkered; }
    void setFreshWaterBunkered(double freshWaterBunkered) { m_freshWaterBunkered = freshWaterBunkered; }

    /// <summary>
    /// Fresh water produced on board by running the fresh water generator, measured in metric tons.
    /// </summary>
    double getFreshWaterProduced() const { return m_freshWaterProduced; }
    void setFreshWaterProduced(double freshWaterProduced) { m_freshWaterProduced = freshWaterProduced; }

    /// <summary>
    /// Fresh water (drinking water) consumed on board, measured in metric tons.
    /// </summary>
    double getFreshWaterConsumed() const { return m_freshWaterConsumed; }
    void setFreshWaterConsumed(double freshWaterConsumed) { m_freshWaterConsumed = freshWaterConsumed; }

    /// <summary>
    /// Technical water (< 15 ppm) produced on board, measured in metric tons.
    /// </summary>
    double getTechnicalWaterProduced() const { return m_technicalWaterProduced; }
    void setTechnicalWaterProduced(double technicalWaterProduced) { m_technicalWaterProduced = technicalWaterProduced; }

    /// <summary>
    /// Technical water (< 15 ppm) consumed on board, measured in metric tons.
    /// </summary>
    double getTechnicalWaterConsumed() const { return m_technicalWaterConsumed; }
    void setTechnicalWaterConsumed(double technicalWaterConsumed) { m_technicalWaterConsumed = technicalWaterConsumed; }

    /// <summary>
    /// Wash water (for exhaust gas cleaning systems) consumed on board, measured in metric tons.
    /// </summary>
    double getWashWaterConsumed() const { return m_washWaterConsumed; }
    void setWashWaterConsumed(double washWaterConsumed) { m_washWaterConsumed = washWaterConsumed; }

    /// <summary>
    /// Fresh drinking water remaining on board, measured in metric tons.
    /// </summary>
    double getFreshWaterRemaining() const { return m_freshWaterRemaining; }
    void setFreshWaterRemaining(double freshWaterRemaining) { m_freshWaterRemaining = freshWaterRemaining; }
};

} // namespace models
} // namespace svd
