add_library(svd
    # Models
    svd/models/arrival_times.cpp
    svd/models/cargo_information.cpp
    svd/models/cylinder_lube_oil_information.cpp
    svd/models/deviation_from_planned.cpp
    svd/models/electricity_consumption.cpp
    svd/models/emissions.cpp
    svd/models/fresh_water.cpp
    svd/models/fuel_and_bunker_information.cpp
    svd/models/general_information.cpp
    svd/models/port_information.cpp
    svd/models/speed_and_distance.cpp
    svd/models/standardised_vessel_dataset.cpp
    svd/models/weather_information.cpp
    
    # Exporters
    svd/exporters/base_exporter.cpp
    svd/exporters/svd_exporter_content.cpp
    svd/exporters/formats/svd_json_exporter.cpp    svd/exporters/formats/svd_xml_exporter.cpp
    svd/exporters/formats/svd_csv_exporter.cpp
    
    # Validators
    svd/validators/errors/validation_error.cpp
    svd/validators/exceptions/validation_exception.cpp
    svd/validators/general_validator.cpp
    svd/validators/standardised_vessel_dataset_validator.cpp
)

target_include_directories(svd
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(svd
    PRIVATE
        nlohmann_json::nlohmann_json
        tinyxml2::tinyxml2
)

# Set target properties
set_target_properties(svd PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Compiler-specific options
if(MSVC)
    target_compile_options(svd PRIVATE /W4)
else()
    target_compile_options(svd PRIVATE -Wall -Wextra -Wpedantic)
endif()
