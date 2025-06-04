#include "svd/exporters/formats/svd_xml_exporter.hpp"
#include "svd/models/standardised_vessel_dataset.hpp"
#include <tinyxml2.h>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace tinyxml2;

namespace svd::exporters::formats {

std::string SvdXmlExporter::getMimeType() const {
    return "application/xml";
}

std::string SvdXmlExporter::getFileExtension() const {
    return ".xml";
}

std::string SvdXmlExporter::getFormatName() const {
    return "XML";
}

std::string SvdXmlExporter::doExport(const svd::models::StandardisedVesselDataset& svd) const {
    XMLDocument doc;
    
    // Create root element
    XMLElement* root = doc.NewElement("StandardisedVesselDataset");
    doc.InsertFirstChild(root);
    
    // Add general information
    XMLElement* general = doc.NewElement("General");
    root->InsertEndChild(general);
    
    general->SetAttribute("eventType", svd.getGeneral().getEventType().c_str());
    general->SetAttribute("imo", svd.getGeneral().getImo().c_str());
    general->SetAttribute("voyageNumber", svd.getGeneral().getVoyageNumber().c_str());
    general->SetAttribute("shipName", svd.getGeneral().getShipName().c_str());
    general->SetAttribute("operationType", svd.getGeneral().getOperationType().c_str());
    general->SetAttribute("operationDescription", svd.getGeneral().getOperationDescription().c_str());
    general->SetAttribute("performanceReportType", svd.getGeneral().getPerformanceReportType().c_str());
    general->SetAttribute("shipLatitude", svd.getGeneral().getShipLatitude());
    general->SetAttribute("shipLongitude", svd.getGeneral().getShipLongitude());
    general->SetAttribute("shipFlagState", svd.getGeneral().getShipFlagState().c_str());
    general->SetAttribute("callSign", svd.getGeneral().getCallSign().c_str());
    general->SetAttribute("mmsi", svd.getGeneral().getMmsi().c_str());
    general->SetAttribute("shipType", svd.getGeneral().getShipType().c_str());
    general->SetAttribute("deadweight", svd.getGeneral().getDeadweight());
    general->SetAttribute("grossTonnage", svd.getGeneral().getGrossTonnage());
    general->SetAttribute("netTonnage", svd.getGeneral().getNetTonnage());
    general->SetAttribute("shipOwner", svd.getGeneral().getShipOwner().c_str());
    general->SetAttribute("shipManager", svd.getGeneral().getShipManager().c_str());
    general->SetAttribute("charterer", svd.getGeneral().getCharterer().c_str());
    general->SetAttribute("lengthOverall", svd.getGeneral().getLengthOverall());
    general->SetAttribute("beam", svd.getGeneral().getBeam());
    general->SetAttribute("depth", svd.getGeneral().getDepth());
    
    // Add port information
    XMLElement* port = doc.NewElement("PortAndRoute");
    root->InsertEndChild(port);
    
    port->SetAttribute("departurePortCode", svd.getPortAndRoute().getDeparturePortCode().c_str());
    port->SetAttribute("departurePortName", svd.getPortAndRoute().getDeparturePortName().c_str());
    port->SetAttribute("arrivalPortCode", svd.getPortAndRoute().getArrivalPortCode().c_str());
    port->SetAttribute("arrivalPortName", svd.getPortAndRoute().getArrivalPortName().c_str());
    port->SetAttribute("routeCode", svd.getPortAndRoute().getRouteCode().c_str());
    port->SetAttribute("routeDescription", svd.getPortAndRoute().getRouteDescription().c_str());
    port->SetAttribute("plannedDistance", svd.getPortAndRoute().getPlannedDistance());
    
    // Add weather information
    XMLElement* weather = doc.NewElement("Weather");
    root->InsertEndChild(weather);
    
    weather->SetAttribute("windSpeed", svd.getWeather().getWindSpeed());
    weather->SetAttribute("windDirection", svd.getWeather().getWindDirection());
    weather->SetAttribute("seaState", svd.getWeather().getSeaState());
    weather->SetAttribute("swellHeight", svd.getWeather().getSwellHeight());
    weather->SetAttribute("swellDirection", svd.getWeather().getSwellDirection());
    weather->SetAttribute("airTemperature", svd.getWeather().getAirTemperature());
    weather->SetAttribute("seaWaterTemperature", svd.getWeather().getSeaWaterTemperature());
    weather->SetAttribute("barometricPressure", svd.getWeather().getBarometricPressure());
    weather->SetAttribute("weatherDescription", svd.getWeather().getWeatherDescription().c_str());
    
    // Convert to string
    XMLPrinter printer;
    doc.Print(&printer);
    
    return std::string(printer.CStr());
}

std::string SvdXmlExporter::generateFilename(const svd::models::StandardisedVesselDataset& svd) const {
    std::ostringstream oss;
    oss << "svd_" << svd.getGeneral().getImo() 
        << "_voyage_" << svd.getGeneral().getVoyageNumber() 
        << "_" << std::time(nullptr) << ".xml";
    return oss.str();
}

} // namespace svd::exporters::formats