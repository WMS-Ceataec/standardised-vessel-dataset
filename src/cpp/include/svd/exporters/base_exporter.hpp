#pragma once

#include "../isvd_exporter.hpp"
#include <memory>
#include <string>

// Forward declaration
namespace svd::models {
    class StandardisedVesselDataset;
}

namespace svd::exporters {

/**
 * @brief Base class for all SVD exporters providing common validation functionality
 */
class BaseExporter : public svd::ISvdExporter
{
public:
    BaseExporter() = default;
    virtual ~BaseExporter() = default;

    // Delete copy constructor and assignment operator
    BaseExporter(const BaseExporter&) = delete;
    BaseExporter& operator=(const BaseExporter&) = delete;
      // Allow move construction and assignment
    BaseExporter(BaseExporter&&) = default;
    BaseExporter& operator=(BaseExporter&&) = default;
    
    // ISvdExporter interface implementation
    std::string exportData(const svd::models::StandardisedVesselDataset& data) const override;
    virtual std::string getMimeType() const = 0;
    virtual std::string getFileExtension() const = 0;
    virtual std::string getFormatName() const = 0;

protected:
    /**
     * @brief Internal export method to be implemented by derived classes
     * @param data The SVD object to export
     * @return Exported data as string
     */
    virtual std::string doExport(const svd::models::StandardisedVesselDataset& data) const = 0;
};

} // namespace svd::exporters
