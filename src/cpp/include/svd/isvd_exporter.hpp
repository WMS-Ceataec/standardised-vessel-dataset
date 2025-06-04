#pragma once

#include <string>

// Forward declaration
namespace svd::models {
    class StandardisedVesselDataset;
}

namespace svd {

/**
 * @brief Interface for SVD data exporters
 * 
 * This interface defines the contract for all SVD data exporters,
 * ensuring consistent export functionality across different formats.
 */
class ISvdExporter {
public:
    virtual ~ISvdExporter() = default;

    /**
     * @brief Export SVD data to the specified format
     * @param data The SVD data to export
     * @return Exported data as a string
     */
    virtual std::string exportData(const svd::models::StandardisedVesselDataset& data) const = 0;

    /**
     * @brief Get the MIME type for this export format
     * @return MIME type string
     */
    virtual std::string getMimeType() const = 0;

    /**
     * @brief Get the file extension for this export format
     * @return File extension string (including the dot)
     */
    virtual std::string getFileExtension() const = 0;

    /**
     * @brief Get a human-readable name for this export format
     * @return Format name string
     */
    virtual std::string getFormatName() const = 0;
};

} // namespace svd
