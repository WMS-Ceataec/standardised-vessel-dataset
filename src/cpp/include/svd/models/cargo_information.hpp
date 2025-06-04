#pragma once

#include <string>
#include <chrono>

namespace svd {
namespace models {

/// <summary>
/// Represents the "Cargo Information" section of the SVD.
/// </summary>
class CargoInformation 
{
private:
    std::string m_cargoDescription;
    double m_grossWeight;
    double m_grossVolume;
    std::string m_billOfLadingReference;
    std::chrono::system_clock::time_point m_billOfLadingIssuedDate;
    int m_totalContainersTeu;
    int m_totalFullContainersTeu;
    int m_totalFullReeferContainersTeu;
    int m_reeferSocketsInUse;

public:
    CargoInformation() = default;    /// <summary>
    /// A description of the referenced packaged cargo.
    /// </summary>
    const std::string& getCargoDescription() const { return m_cargoDescription; }
    void setCargoDescription(const std::string& value) { m_cargoDescription = value; }

    /// <summary>
    /// The combined weight or mass of the referenced packaged cargo and its packaging from the shipping data, in kilograms (kg).
    /// </summary>
    double getGrossWeight() const { return m_grossWeight; }
    void setGrossWeight(double value) { m_grossWeight = value; }

    /// <summary>
    /// A measure of the gross volume, normally calculated by multiplying the maximum length, width, and height of the cargo item.
    /// </summary>
    double getGrossVolume() const { return m_grossVolume; }
    void setGrossVolume(double value) { m_grossVolume = value; }

    /// <summary>
    /// A reference number issued on the bill of lading.
    /// </summary>
    const std::string& getBillOfLadingReference() const { return m_billOfLadingReference; }
    void setBillOfLadingReference(const std::string& value) { m_billOfLadingReference = value; }    /// <summary>
    /// The date when the bill of lading is issued.
    /// </summary>
    const std::chrono::system_clock::time_point& getBillOfLadingIssuedDate() const { return m_billOfLadingIssuedDate; }
    void setBillOfLadingIssuedDate(const std::chrono::system_clock::time_point& value) { m_billOfLadingIssuedDate = value; }

    /// <summary>
    /// The total number of containers onboard (full and empty), measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    int getTotalContainersTEU() const { return m_totalContainersTeu; }
    void setTotalContainersTEU(int value) { m_totalContainersTeu = value; }

    /// <summary>
    /// The total number of full containers onboard, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    int getTotalFullContainersTEU() const { return m_totalFullContainersTeu; }
    void setTotalFullContainersTEU(int value) { m_totalFullContainersTeu = value; }

    /// <summary>
    /// The total number of full reefer containers onboard in use, measured in TEU (Twenty-Foot Equivalent Unit).
    /// </summary>
    int getTotalFullReeferContainersTEU() const { return m_totalFullReeferContainersTeu; }
    void setTotalFullReeferContainersTEU(int value) { m_totalFullReeferContainersTeu = value; }

    /// <summary>
    /// The total number of reefer power sockets in use during the voyage.
    /// </summary>
    int getReeferSocketsInUse() const { return m_reeferSocketsInUse; }
    void setReeferSocketsInUse(int value) { m_reeferSocketsInUse = value; }
};

} // namespace models
} // namespace svd
