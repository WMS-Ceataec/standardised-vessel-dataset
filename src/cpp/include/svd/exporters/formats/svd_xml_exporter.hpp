#pragma once

#include "../base_exporter.hpp"
#include "format_exporters.hpp"

// Forward declaration
namespace svd::models {
    class StandardisedVesselDataset;
}

namespace svd::exporters::formats {

/**
 * @brief XML format exporter for Standardised Vessel Datasets
 */
class SvdXmlExporter : public BaseExporter {
public:
    SvdXmlExporter() = default;
    ~SvdXmlExporter() override = default;

    // Delete copy constructor and assignment operator
    SvdXmlExporter(const SvdXmlExporter&) = delete;
    SvdXmlExporter& operator=(const SvdXmlExporter&) = delete;
    
    // Allow move construction and assignment
    SvdXmlExporter(SvdXmlExporter&&) = default;
    SvdXmlExporter& operator=(SvdXmlExporter&&) = default;

    // ISvdExporter interface implementation
    std::string getMimeType() const override;
    std::string getFileExtension() const override;
    std::string getFormatName() const override;

protected:
    std::string doExport(const svd::models::StandardisedVesselDataset& svd) const override;

private:
    std::string generateFilename(const svd::models::StandardisedVesselDataset& svd) const;
};

} // namespace svd::exporters::formats
