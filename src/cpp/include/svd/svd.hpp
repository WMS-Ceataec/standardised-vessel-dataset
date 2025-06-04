#pragma once

/**
 * @file svd.hpp
 * @brief Main header file for the Standardised Vessel Dataset C++ library
 * 
 * This header includes all the necessary components for working with
 * Standardised Vessel Datasets including models, exporters, and validators.
 */

// Models
#include "models/standardised_vessel_dataset.hpp"
#include "models/general_information.hpp"
#include "models/port_information.hpp"
#include "models/arrival_times.hpp"
#include "models/weather_information.hpp"
#include "models/cargo_information.hpp"
#include "models/fuel_and_bunker_information.hpp"
#include "models/emissions.hpp"
#include "models/speed_and_distance.hpp"
#include "models/electricity_consumption.hpp"
#include "models/fresh_water.hpp"
#include "models/cylinder_lube_oil_information.hpp"
#include "models/deviation_from_planned.hpp"

// Exporters
#include "exporters/isvd_exporter.hpp"
#include "exporters/svd_exporter_content.hpp"
#include "exporters/base_exporter.hpp"
#include "exporters/formats/format_exporters.hpp"
#include "exporters/formats/svd_json_exporter.hpp"
#include "exporters/formats/svd_xml_exporter.hpp"
#include "exporters/formats/svd_csv_exporter.hpp"

// Validators
#include "validators/ivalidator.hpp"
#include "validators/errors/validation_error.hpp"
#include "validators/exceptions/validation_exception.hpp"

/**
 * @namespace svd
 * @brief Main namespace for the Standardised Vessel Dataset library
 */
namespace svd {

/**
 * @namespace svd::models
 * @brief Contains all data model classes for the SVD
 */
namespace models {}

/**
 * @namespace svd::exporters
 * @brief Contains exporter interfaces and implementations
 */
namespace exporters {
    /**
     * @namespace svd::exporters::formats
     * @brief Contains format-specific exporter implementations
     */
    namespace formats {}
}

/**
 * @namespace svd::validators
 * @brief Contains validation interfaces and implementations
 */
namespace validators {}

} // namespace svd
