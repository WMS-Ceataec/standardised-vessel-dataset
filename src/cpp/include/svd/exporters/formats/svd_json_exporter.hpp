#pragma once

#include "../base_exporter.hpp"
#include "format_exporters.hpp"

// Forward declaration
namespace svd::models {
    class StandardisedVesselDataset;
}

namespace svd::exporters::formats {

/**
 * @brief JSON format exporter for Standardised Vessel Datasets
 */
class SvdJsonExporter : public svd::exporters::BaseExporter {
public:
    SvdJsonExporter() = default;
    ~SvdJsonExporter() override = default;

    // Delete copy constructor and assignment operator
    SvdJsonExporter(const SvdJsonExporter&) = delete;
    SvdJsonExporter& operator=(const SvdJsonExporter&) = delete;
    
    // Allow move construction and assignment
    SvdJsonExporter(SvdJsonExporter&&) = default;
    SvdJsonExporter& operator=(SvdJsonExporter&&) = default;

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
