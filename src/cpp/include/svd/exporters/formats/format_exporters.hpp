#pragma once

#include "../../isvd_exporter.hpp"

namespace svd::exporters {

/**
 * @brief Interface for exporting Standardised Vessel Datasets (SVD) to JSON format
 */
class ISvdJsonExporter : public svd::ISvdExporter {
public:
    ~ISvdJsonExporter() override = default;
};

/**
 * @brief Interface for exporting Standardised Vessel Datasets (SVD) to XML format
 */
class ISvdXmlExporter : public svd::ISvdExporter {
public:
    ~ISvdXmlExporter() override = default;
};

/**
 * @brief Interface for exporting Standardised Vessel Datasets (SVD) to CSV format
 */
class ISvdCsvExporter : public svd::ISvdExporter {
public:
    ~ISvdCsvExporter() override = default;
};

} // namespace svd::exporters
