#pragma once

#include "svd_exporter_content.hpp"
#include "../models/standardised_vessel_dataset.hpp"
#include <memory>
#include <future>

namespace svd::validators {
class ValidationException;
}

namespace svd::exporters {

/**
 * @brief Generic interface for exporting Standardised Vessel Datasets (SVD)
 */
class ISvdExporter
{
public:
    virtual ~ISvdExporter() = default;

    /**
     * @brief Export SVD for output format (XML, JSON, CSV)
     * @param svd The Standardised Vessel Dataset to export. It should not be null.
     * @return Returns SvdExporterContent containing the exported data
     * @throws std::invalid_argument Thrown if the input svd is null
     * @throws ValidationException Thrown if the provided model is not valid
     */
    virtual std::future<SvdExporterContent> exportAsync(const models::StandardisedVesselDataset& svd) = 0;
};

} // namespace svd::exporters
