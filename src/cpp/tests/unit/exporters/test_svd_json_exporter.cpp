#include <gtest/gtest.h>
#include <svd/exporters/formats/svd_json_exporter.hpp>
#include <svd/validators/standardised_vessel_dataset_validator.hpp>
#include <svd/models/standardised_vessel_dataset.hpp>
#include <memory>
#include <chrono>

using namespace svd;

class SvdJsonExporterTest : public ::testing::Test {
protected:
    void SetUp() override {
        exporter = std::make_unique<exporters::formats::SvdJsonExporter>();
        
        // Create a valid test SVD
        test_svd = std::make_unique<models::StandardisedVesselDataset>();
        test_svd->getGeneral().setImo("1234567");
        test_svd->getGeneral().setShipName("Test Vessel");
        test_svd->getGeneral().setShipReportingDate(std::chrono::system_clock::now());
        test_svd->getPortAndRoute().setDeparturePortCode("SEGOT");
    }

    std::unique_ptr<exporters::formats::SvdJsonExporter> exporter;
    std::unique_ptr<models::StandardisedVesselDataset> test_svd;
};

TEST_F(SvdJsonExporterTest, ExportValidSvd) {
    auto result = exporter->exportData(*test_svd);
    
    EXPECT_FALSE(result.empty());
    // Check that it contains expected JSON structure
    EXPECT_TRUE(result.find("\"general\"") != std::string::npos);
    EXPECT_TRUE(result.find("\"imo\"") != std::string::npos);
}

TEST_F(SvdJsonExporterTest, ExporterProperties) {
    EXPECT_EQ(exporter->getMimeType(), "application/json");
    EXPECT_EQ(exporter->getFileExtension(), ".json");
    EXPECT_EQ(exporter->getFormatName(), "JSON");
}

TEST_F(SvdJsonExporterTest, ContentContainsJsonData) {
    auto result = exporter->exportData(*test_svd);
    
    // Check that it contains expected JSON structure
    EXPECT_TRUE(result.find("\"general\"") != std::string::npos);
    EXPECT_TRUE(result.find("\"imo\"") != std::string::npos);
    EXPECT_TRUE(result.find("1234567") != std::string::npos);
    EXPECT_TRUE(result.find("Test Vessel") != std::string::npos);
}
