#include "svd/exporters/base_exporter.hpp"
#include "svd/models/standardised_vessel_dataset.hpp"

namespace svd::exporters {

std::string BaseExporter::exportData(const svd::models::StandardisedVesselDataset& data) const {
    return doExport(data);
}

} // namespace svd::exporters
