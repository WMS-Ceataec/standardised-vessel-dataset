#pragma once

#include <string>
#include <chrono>
#include <optional>

namespace svd::models {

/**
 * @brief Represents the "General" section of SVD * 
 * Contains general information about the vessel and reporting event.
 */
class GeneralInformation 
{
public:
    GeneralInformation() = default;
    ~GeneralInformation() = default;
    
    // Copy and move constructors/assignment operators
    GeneralInformation(const GeneralInformation&) = default;
    GeneralInformation& operator=(const GeneralInformation&) = default;
    GeneralInformation(GeneralInformation&&) = default;
    GeneralInformation& operator=(GeneralInformation&&) = default;    // Getters
    const std::string& getEventType() const { return m_eventType; }
    const std::string& getOperationType() const { return m_operationType; }
    const std::string& getOperationDescription() const { return m_operationDescription; }
    const std::string& getPerformanceReportType() const { return m_performanceReportType; }
    std::chrono::duration<double, std::ratio<3600>> getElapsedTime() const { return m_elapsedTime; }
    double getShipLatitude() const { return m_shipLatitude; }
    double getShipLongitude() const { return m_shipLongitude; }
    const std::chrono::system_clock::time_point& getShipReportingDate() const { return m_shipReportingDate; }
    const std::string& getShipFlagState() const { return m_shipFlagState; }    const std::string& getShipName() const { return m_shipName; }
    const std::string& getImo() const { return m_imo; }
    const std::string& getVoyageNumber() const { return m_voyageNumber; }
    const std::string& getCallSign() const { return m_callSign; }
    const std::string& getMmsi() const { return m_mmsi; }
    const std::string& getShipType() const { return m_shipType; }
    double getDeadweight() const { return m_deadweight; }
    double getGrossTonnage() const { return m_grossTonnage; }
    double getNetTonnage() const { return m_netTonnage; }
    const std::string& getShipOwner() const { return m_shipOwner; }
    const std::string& getShipManager() const { return m_shipManager; }
    const std::string& getCharterer() const { return m_charterer; }
    double getLengthOverall() const { return m_lengthOverall; }
    double getBeam() const { return m_beam; }
    double getDepth() const { return m_depth; }
      // Setters
    void setEventType(const std::string& eventType) { m_eventType = eventType; }
    void setOperationType(const std::string& operationType) { m_operationType = operationType; }
    void setOperationDescription(const std::string& operationDescription) { m_operationDescription = operationDescription; }
    void setPerformanceReportType(const std::string& performanceReportType) { m_performanceReportType = performanceReportType; }
    void setElapsedTime(std::chrono::duration<double, std::ratio<3600>> elapsedTime) { m_elapsedTime = elapsedTime; }
    void setShipLatitude(double shipLatitude) { m_shipLatitude = shipLatitude; }
    void setShipLongitude(double shipLongitude) { m_shipLongitude = shipLongitude; }
    void setShipReportingDate(const std::chrono::system_clock::time_point& shipReportingDate) { m_shipReportingDate = shipReportingDate; }
    void setShipFlagState(const std::string& shipFlagState) { m_shipFlagState = shipFlagState; }    void setShipName(const std::string& shipName) { m_shipName = shipName; }
    void setImo(const std::string& imo) { m_imo = imo; }
    void setVoyageNumber(const std::string& voyageNumber) { m_voyageNumber = voyageNumber; }
    void setCallSign(const std::string& callSign) { m_callSign = callSign; }
    void setMmsi(const std::string& mmsi) { m_mmsi = mmsi; }
    void setShipType(const std::string& shipType) { m_shipType = shipType; }
    void setDeadweight(double deadweight) { m_deadweight = deadweight; }
    void setGrossTonnage(double grossTonnage) { m_grossTonnage = grossTonnage; }
    void setNetTonnage(double netTonnage) { m_netTonnage = netTonnage; }
    void setShipOwner(const std::string& shipOwner) { m_shipOwner = shipOwner; }
    void setShipManager(const std::string& shipManager) { m_shipManager = shipManager; }
    void setCharterer(const std::string& charterer) { m_charterer = charterer; }
    void setLengthOverall(double lengthOverall) { m_lengthOverall = lengthOverall; }
    void setBeam(double beam) { m_beam = beam; }
    void setDepth(double depth) { m_depth = depth; }

private:
    std::string m_eventType;
    std::string m_operationType;
    std::string m_operationDescription;
    std::string m_performanceReportType;
    std::chrono::duration<double, std::ratio<3600>> m_elapsedTime{};
    double m_shipLatitude = 0.0;
    double m_shipLongitude = 0.0;
    std::chrono::system_clock::time_point m_shipReportingDate;
    std::string m_shipFlagState;    std::string m_shipName;
    std::string m_imo;
    std::string m_voyageNumber;
    std::string m_callSign;
    std::string m_mmsi;
    std::string m_shipType;
    double m_deadweight = 0.0;
    double m_grossTonnage = 0.0;
    double m_netTonnage = 0.0;
    std::string m_shipOwner;
    std::string m_shipManager;
    std::string m_charterer;
    double m_lengthOverall = 0.0;
    double m_beam = 0.0;
    double m_depth = 0.0;
};

} // namespace svd::models
