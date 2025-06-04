#include <gtest/gtest.h>
#include <svd/models/general_information.hpp>
#include <chrono>

using namespace svd::models;

class GeneralInformationTest : public ::testing::Test {
protected:
    void SetUp() override {
        general_info = std::make_unique<GeneralInformation>();
    }

    std::unique_ptr<GeneralInformation> general_info;
};

TEST_F(GeneralInformationTest, DefaultConstructor) {
    EXPECT_TRUE(general_info->getEventType().empty());
    EXPECT_TRUE(general_info->getShipName().empty());
    EXPECT_TRUE(general_info->getImo().empty());
    EXPECT_EQ(general_info->getShipLatitude(), 0.0);
    EXPECT_EQ(general_info->getShipLongitude(), 0.0);
}

TEST_F(GeneralInformationTest, SettersAndGetters) {
    const std::string imo = "1234567";
    const std::string ship_name = "Test Vessel";
    const double latitude = 59.9139;
    const double longitude = 18.4956;
    
    general_info->setImo(imo);
    general_info->setShipName(ship_name);
    general_info->setShipLatitude(latitude);
    general_info->setShipLongitude(longitude);
    
    EXPECT_EQ(general_info->getImo(), imo);
    EXPECT_EQ(general_info->getShipName(), ship_name);
    EXPECT_EQ(general_info->getShipLatitude(), latitude);
    EXPECT_EQ(general_info->getShipLongitude(), longitude);
}

TEST_F(GeneralInformationTest, DateTimeHandling) {
    auto now = std::chrono::system_clock::now();
    general_info->setShipReportingDate(now);
    
    EXPECT_EQ(general_info->getShipReportingDate(), now);
}

TEST_F(GeneralInformationTest, CopyConstructor) {
    general_info->setImo("1234567");
    general_info->setShipName("Test Vessel");
    general_info->setShipLatitude(59.9139);
    
    GeneralInformation copy(*general_info);
    
    EXPECT_EQ(copy.getImo(), general_info->getImo());
    EXPECT_EQ(copy.getShipName(), general_info->getShipName());
    EXPECT_EQ(copy.getShipLatitude(), general_info->getShipLatitude());
}
