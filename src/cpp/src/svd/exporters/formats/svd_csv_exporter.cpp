#include "svd/exporters/formats/svd_csv_exporter.hpp"
#include "svd/models/standardised_vessel_dataset.hpp"
#include <sstream>
#include <iomanip>
#include <chrono>

namespace svd::exporters::formats {

std::string SvdCsvExporter::getMimeType() const {
    return "text/csv";
}

std::string SvdCsvExporter::getFileExtension() const {
    return ".csv";
}

std::string SvdCsvExporter::getFormatName() const {
    return "CSV";
}

std::string SvdCsvExporter::doExport(const svd::models::StandardisedVesselDataset& svd) const {
    std::ostringstream csv;
    
    // CSV Header
    csv << "Field,Value\n";
    
    // General information
    csv << "EventType," << svd.getGeneral().getEventType() << "\n";
    csv << "IMO," << svd.getGeneral().getImo() << "\n";
    csv << "VoyageNumber," << svd.getGeneral().getVoyageNumber() << "\n";
    csv << "ShipName," << svd.getGeneral().getShipName() << "\n";
    csv << "OperationType," << svd.getGeneral().getOperationType() << "\n";
    csv << "OperationDescription," << svd.getGeneral().getOperationDescription() << "\n";
    csv << "PerformanceReportType," << svd.getGeneral().getPerformanceReportType() << "\n";
    csv << "ShipLatitude," << std::fixed << std::setprecision(6) << svd.getGeneral().getShipLatitude() << "\n";
    csv << "ShipLongitude," << std::fixed << std::setprecision(6) << svd.getGeneral().getShipLongitude() << "\n";
    csv << "ShipFlagState," << svd.getGeneral().getShipFlagState() << "\n";
    csv << "CallSign," << svd.getGeneral().getCallSign() << "\n";
    csv << "MMSI," << svd.getGeneral().getMmsi() << "\n";
    csv << "ShipType," << svd.getGeneral().getShipType() << "\n";
    csv << "Deadweight," << std::fixed << std::setprecision(2) << svd.getGeneral().getDeadweight() << "\n";
    csv << "GrossTonnage," << std::fixed << std::setprecision(2) << svd.getGeneral().getGrossTonnage() << "\n";
    csv << "NetTonnage," << std::fixed << std::setprecision(2) << svd.getGeneral().getNetTonnage() << "\n";
    csv << "ShipOwner," << svd.getGeneral().getShipOwner() << "\n";
    csv << "ShipManager," << svd.getGeneral().getShipManager() << "\n";
    csv << "Charterer," << svd.getGeneral().getCharterer() << "\n";
    csv << "LengthOverall," << std::fixed << std::setprecision(2) << svd.getGeneral().getLengthOverall() << "\n";
    csv << "Beam," << std::fixed << std::setprecision(2) << svd.getGeneral().getBeam() << "\n";
    csv << "Depth," << std::fixed << std::setprecision(2) << svd.getGeneral().getDepth() << "\n";
    
    // Port information
    csv << "DeparturePortCode," << svd.getPortAndRoute().getDeparturePortCode() << "\n";
    csv << "DeparturePortName," << svd.getPortAndRoute().getDeparturePortName() << "\n";
    csv << "ArrivalPortCode," << svd.getPortAndRoute().getArrivalPortCode() << "\n";
    csv << "ArrivalPortName," << svd.getPortAndRoute().getArrivalPortName() << "\n";
    csv << "RouteCode," << svd.getPortAndRoute().getRouteCode() << "\n";
    csv << "RouteDescription," << svd.getPortAndRoute().getRouteDescription() << "\n";
    csv << "PlannedDistance," << std::fixed << std::setprecision(2) << svd.getPortAndRoute().getPlannedDistance() << "\n";
    
    // Weather information
    csv << "WindSpeed," << std::fixed << std::setprecision(2) << svd.getWeather().getWindSpeed() << "\n";
    csv << "WindDirection," << std::fixed << std::setprecision(2) << svd.getWeather().getWindDirection() << "\n";
    csv << "SeaState," << std::fixed << std::setprecision(2) << svd.getWeather().getSeaState() << "\n";
    csv << "SwellHeight," << std::fixed << std::setprecision(2) << svd.getWeather().getSwellHeight() << "\n";
    csv << "SwellDirection," << std::fixed << std::setprecision(2) << svd.getWeather().getSwellDirection() << "\n";
    csv << "AirTemperature," << std::fixed << std::setprecision(2) << svd.getWeather().getAirTemperature() << "\n";
    csv << "SeaWaterTemperature," << std::fixed << std::setprecision(2) << svd.getWeather().getSeaWaterTemperature() << "\n";
    csv << "BarometricPressure," << std::fixed << std::setprecision(2) << svd.getWeather().getBarometricPressure() << "\n";
    csv << "WeatherDescription," << svd.getWeather().getWeatherDescription() << "\n";
    
    return csv.str();
}

std::string SvdCsvExporter::generateFilename(const svd::models::StandardisedVesselDataset& svd) const {
    std::ostringstream oss;
    oss << "svd_" << svd.getGeneral().getImo() 
        << "_voyage_" << svd.getGeneral().getVoyageNumber() 
        << "_" << std::time(nullptr) << ".csv";
    return oss.str();
}

} // namespace svd::exporters::formats