#include <gtest/gtest.h>
#include <svd/models/standardised_vessel_dataset.hpp>

using namespace svd::models;

class StandardisedVesselDatasetTest : public ::testing::Test {
protected:
    void SetUp() override {
        svd = std::make_unique<StandardisedVesselDataset>();
    }

    std::unique_ptr<StandardisedVesselDataset> svd;
};

TEST_F(StandardisedVesselDatasetTest, DefaultConstructor) {
    EXPECT_TRUE(svd->getGeneral().getShipName().empty());
    EXPECT_TRUE(svd->getPortAndRoute().getDeparturePortCode().empty());
}

TEST_F(StandardisedVesselDatasetTest, SetGeneralInformation) {
    GeneralInformation general;
    general.setImo("1234567");
    general.setShipName("Test Vessel");
    
    svd->setGeneral(general);
    
    EXPECT_EQ(svd->getGeneral().getImo(), "1234567");
    EXPECT_EQ(svd->getGeneral().getShipName(), "Test Vessel");
}

TEST_F(StandardisedVesselDatasetTest, ModifyGeneralInformationDirectly) {
    svd->getGeneral().setImo("7654321");
    svd->getGeneral().setShipName("Direct Test Vessel");
    
    EXPECT_EQ(svd->getGeneral().getImo(), "7654321");
    EXPECT_EQ(svd->getGeneral().getShipName(), "Direct Test Vessel");
}

TEST_F(StandardisedVesselDatasetTest, CopyConstructor) {
    svd->getGeneral().setImo("1234567");
    svd->getGeneral().setShipName("Test Vessel");
    svd->getPortAndRoute().setDeparturePortCode("SEGOT");
    
    StandardisedVesselDataset copy(*svd);
    
    EXPECT_EQ(copy.getGeneral().getImo(), svd->getGeneral().getImo());
    EXPECT_EQ(copy.getGeneral().getShipName(), svd->getGeneral().getShipName());
    EXPECT_EQ(copy.getPortAndRoute().getDeparturePortCode(), svd->getPortAndRoute().getDeparturePortCode());
}
