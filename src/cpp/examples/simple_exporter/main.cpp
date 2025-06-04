#include <svd/svd.hpp>
#include <svd/validators/standardised_vessel_dataset_validator.hpp>
#include <svd/exporters/formats/svd_json_exporter.hpp>
#include <svd/exporters/formats/svd_xml_exporter.hpp>
#include <svd/exporters/formats/svd_csv_exporter.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>

using namespace svd;

/**
 * @brief Creates a sample SVD object for demonstration
 */
models::StandardisedVesselDataset createSampleSvd() {
    models::StandardisedVesselDataset svd;
    
    // Set general information
    auto& general = svd.getGeneral();
    general.setImo("1234567");
    general.setShipName("Sample Vessel");
    general.setEventType("Noon Report");
    general.setOperationType("Sailing");
    general.setOperationDescription("Transit to destination port");
    general.setPerformanceReportType("Standard");
    general.setShipLatitude(59.9139);  // Stockholm coordinates
    general.setShipLongitude(18.4956);
    general.setShipReportingDate(std::chrono::system_clock::now());
    general.setShipFlagState("SE");
    general.setCallSign("SAMPLE1");
    general.setMmsi("123456789");
    general.setShipType("Container Ship");
    general.setDeadweight(50000.0);
    general.setGrossTonnage(35000.0);
    general.setNetTonnage(25000.0);
    general.setShipOwner("Sample Shipping Company");
    general.setShipManager("Sample Management Ltd");
    general.setCharterer("Sample Charterer");
    general.setLengthOverall(200.0);
    general.setBeam(30.0);
    general.setDepth(15.0);
    
    // Set port information
    auto& port = svd.getPortAndRoute();
    port.setDeparturePortCode("SEGOT");
    port.setDeparturePortName("Gothenburg");
    port.setArrivalPortCode("DEHAM");
    port.setArrivalPortName("Hamburg");
    port.setRouteCode("ROUTE1");
    port.setRouteDescription("Baltic Sea route");
    port.setPlannedDistance(650.0);
    
    // Set weather information
    auto& weather = svd.getWeather();
    weather.setWindSpeed(15.0);
    weather.setWindDirection(225.0);
    weather.setSeaState(3.0);
    weather.setSwellHeight(2.0);
    weather.setSwellDirection(230.0);
    weather.setAirTemperature(12.0);
    weather.setSeaWaterTemperature(8.0);
    weather.setBarometricPressure(1013.25);
    weather.setWeatherDescription("Moderate winds, partly cloudy");
    
    return svd;
}

/**
 * @brief Saves content to a file
 */
void saveToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "Successfully wrote file: " << filename << std::endl;
    } else {
        std::cerr << "Failed to write file: " << filename << std::endl;
    }
}

/**
 * @brief Demonstrates SVD export functionality
 */
int main() {
    try {
        std::cout << "Standardised Vessel Dataset C++ Library Demo\n";
        std::cout << "============================================\n\n";
        
        // Create sample data
        auto svd = createSampleSvd();
        std::cout << "Created sample SVD for vessel: " << svd.getGeneral().getShipName() 
                  << " (IMO: " << svd.getGeneral().getImo() << ")\n\n";
          // Create exporters (no validator needed for simple export)
        auto jsonExporter = std::make_unique<exporters::formats::SvdJsonExporter>();
        auto xmlExporter = std::make_unique<exporters::formats::SvdXmlExporter>();
        auto csvExporter = std::make_unique<exporters::formats::SvdCsvExporter>();
        
        // Export to JSON
        std::cout << "Exporting to JSON..." << std::endl;
        auto jsonContent = jsonExporter->exportData(svd);
        saveToFile("sample_export.json", jsonContent);
        
        // Export to XML
        std::cout << "Exporting to XML..." << std::endl;
        auto xmlContent = xmlExporter->exportData(svd);
        saveToFile("sample_export.xml", xmlContent);
        
        // Export to CSV
        std::cout << "Exporting to CSV..." << std::endl;
        auto csvContent = csvExporter->exportData(svd);
        saveToFile("sample_export.csv", csvContent);
        
        std::cout << "\nAll exports completed successfully!\n";
          } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
