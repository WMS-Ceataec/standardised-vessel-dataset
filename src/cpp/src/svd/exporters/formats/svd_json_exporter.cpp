#include "svd/exporters/formats/svd_json_exporter.hpp"
#include "svd/models/standardised_vessel_dataset.hpp"
#include <nlohmann/json.hpp>
#include <sstream>
#include <iomanip>
#include <chrono>

namespace svd::exporters::formats {

std::string SvdJsonExporter::getMimeType() const {
    return "application/json";
}

std::string SvdJsonExporter::getFileExtension() const {
    return ".json";
}

std::string SvdJsonExporter::getFormatName() const {
    return "JSON";
}

std::string SvdJsonExporter::doExport(const svd::models::StandardisedVesselDataset& svd) const {
    nlohmann::json j;
    
    // Add general information
    nlohmann::json general;
    const auto& gen = svd.getGeneral();
    
    general["eventType"] = gen.getEventType();
    general["imo"] = gen.getImo();
    general["voyageNumber"] = gen.getVoyageNumber();
    general["shipName"] = gen.getShipName();
    general["operationType"] = gen.getOperationType();
    general["operationDescription"] = gen.getOperationDescription();
    general["performanceReportType"] = gen.getPerformanceReportType();
    general["shipLatitude"] = gen.getShipLatitude();
    general["shipLongitude"] = gen.getShipLongitude();
    general["shipFlagState"] = gen.getShipFlagState();
    general["callSign"] = gen.getCallSign();
    general["mmsi"] = gen.getMmsi();
    general["shipType"] = gen.getShipType();
    general["deadweight"] = gen.getDeadweight();
    general["grossTonnage"] = gen.getGrossTonnage();
    general["netTonnage"] = gen.getNetTonnage();
    general["shipOwner"] = gen.getShipOwner();
    general["shipManager"] = gen.getShipManager();
    general["charterer"] = gen.getCharterer();
    general["lengthOverall"] = gen.getLengthOverall();
    general["beam"] = gen.getBeam();
    general["depth"] = gen.getDepth();
    
    // Convert time_point to ISO 8601 string
    auto time_t = std::chrono::system_clock::to_time_t(gen.getShipReportingDate());
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&time_t), "%Y-%m-%dT%H:%M:%SZ");
    general["shipReportingDate"] = ss.str();
    
    j["general"] = general;
    
    // Add port and route information
    nlohmann::json portAndRoute;
    const auto& port = svd.getPortAndRoute();
    
    portAndRoute["departurePortCode"] = port.getDeparturePortCode();
    portAndRoute["departurePortName"] = port.getDeparturePortName();
    portAndRoute["arrivalPortCode"] = port.getArrivalPortCode();
    portAndRoute["arrivalPortName"] = port.getArrivalPortName();
    
    j["portAndRoute"] = portAndRoute;
    
    // Add arrival times (simplified implementation)
    nlohmann::json arrivalTimes;
    j["arrivalTimes"] = arrivalTimes;
    
    // Add weather information (simplified implementation)
    nlohmann::json weather;
    j["weather"] = weather;
    
    return j.dump(4); // Pretty print with 4-space indentation
}

std::string SvdJsonExporter::generateFilename(const svd::models::StandardisedVesselDataset& svd) const {
    std::stringstream filename;
    filename << "SVD_" << svd.getGeneral().getImo() << "_";
    
    auto time_t = std::chrono::system_clock::to_time_t(svd.getGeneral().getShipReportingDate());
    filename << std::put_time(std::gmtime(&time_t), "%Y-%m-%d");
    filename << ".json";
    
    return filename.str();
}

} // namespace svd::exporters::formats
