#pragma once

#include "../base_exporter.hpp"
#include "format_exporters.hpp"

// Forward declaration
namespace svd::models {
    class StandardisedVesselDataset;
}

namespace svd::exporters::formats {

/**
 * @brief CSV format exporter for Standardised Vessel Datasets
 */
class SvdCsvExporter : public BaseExporter {
public:
    SvdCsvExporter() = default;
    ~SvdCsvExporter() override = default;

    // Delete copy constructor and assignment operator
    SvdCsvExporter(const SvdCsvExporter&) = delete;
    SvdCsvExporter& operator=(const SvdCsvExporter&) = delete;
    
    // Allow move construction and assignment
    SvdCsvExporter(SvdCsvExporter&&) = default;
    SvdCsvExporter& operator=(SvdCsvExporter&&) = default;

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
