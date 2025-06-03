cmake_minimum_required(VERSION 3.20)

project(StandardisedVesselDataset
    VERSION 1.0.0
    DESCRIPTION "C++ wrapper for Standardised Vessel Dataset library"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(SVD_BUILD_TESTS "Build tests" ON)
option(SVD_BUILD_EXAMPLES "Build examples" ON)
option(SVD_BUILD_DOCS "Build documentation" OFF)

# Include FetchContent for dependencies
include(FetchContent)

# nlohmann/json for JSON support
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json)

# TinyXML2 for XML support
FetchContent_Declare(
    tinyxml2
    GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
    GIT_TAG 10.0.0
)
FetchContent_MakeAvailable(tinyxml2)

# CSV parser library
FetchContent_Declare(
    fast-cpp-csv-parser
    GIT_REPOSITORY https://github.com/ben-strasser/fast-cpp-csv-parser.git
    GIT_TAG master
)
FetchContent_MakeAvailable(fast-cpp-csv-parser)

# Add the main library
add_subdirectory(src)

# Add tests if enabled
if(SVD_BUILD_TESTS)
    # Google Test
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    add_subdirectory(tests)
endif()

# Add examples if enabled
if(SVD_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Add documentation if enabled
if(SVD_BUILD_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        add_subdirectory(docs)
    endif()
endif()

# Install configuration
include(GNUInstallDirs)

# Install targets
install(TARGETS svd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install headers
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)
