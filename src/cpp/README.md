# Standardised Vessel Dataset - C++ Implementation

This is a C++ wrapper library for the Standardised Vessel Dataset, providing a complete implementation that mirrors the functionality of the C# version.

## Overview

The Standardised Vessel Dataset (SVD) is a standardized data format for vessel reporting and maritime data exchange. This C++ library provides:

- Complete model classes for all SVD data sections
- Support for JSON, XML, and CSV export formats
- Comprehensive validation framework
- Cross-platform compatibility
- Modern C++20 features

## Features

### Model Classes
- `GeneralInformation` - General vessel and voyage information
- `PortInformation` - Port and route details
- `ArrivalTimes` - Arrival and departure time information
- `WeatherInformation` - Weather and sea conditions
- `CargoInformation` - Cargo details and container information
- `FuelAndBunkerInformation` - Fuel consumption and bunker data
- `Emissions` - CO2, CH4, and N2O emission data
- `SpeedAndDistance` - Speed, distance, and navigation data
- `ElectricityConsumption` - Electrical power consumption details
- `FreshWater` - Fresh water production and consumption
- `CylinderLubeOilInformation` - Lubrication oil data
- `DeviationFromPlanned` - Voyage deviation information

### Export Formats
- **JSON Export**: Using nlohmann/json library
- **XML Export**: Using TinyXML2 library
- **CSV Export**: Custom implementation with configurable delimiters

### Validation Framework
- Interface-based validation system
- Extensible validation rules
- Detailed error reporting
- Exception-based error handling

## Dependencies

The library uses the following open-source dependencies (automatically fetched via CMake):

- **nlohmann/json** (v3.11.3) - JSON serialization and deserialization
- **TinyXML2** (v10.0.0) - XML processing
- **fast-cpp-csv-parser** - CSV parsing (for CSV export functionality)
- **GoogleTest** (v1.14.0) - Unit testing framework (development only)

All dependencies are automatically fetched using CMake's FetchContent.

## Building

### Prerequisites
- CMake 3.20 or higher
- C++20 compatible compiler:
  - GCC 10+ 
  - Clang 10+
  - MSVC 2019+ (Visual Studio 2019 or newer)
  - AppleClang (Xcode 12+)

### Quick Start

```bash
# Clone the repository
git clone <repository-url>
cd standardised-vessel-dataset/src/cpp

# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the library and examples
cmake --build . --config Release

# Run tests to verify everything works
ctest -C Release --output-on-failure
```

### Platform-Specific Instructions

#### Windows (Visual Studio)
```powershell
# Using PowerShell
mkdir build
cd build
cmake ..
cmake --build . --config Release
ctest -C Release --output-on-failure
```

#### Linux/macOS
```bash
mkdir build
cd build
cmake ..
make -j$(nproc)  # Linux
make -j$(sysctl -n hw.ncpu)  # macOS
ctest --output-on-failure
```

### Build Options

```bash
# Disable tests (default: ON)
cmake -DSVD_BUILD_TESTS=OFF ..

# Disable examples (default: ON)
cmake -DSVD_BUILD_EXAMPLES=OFF ..

# Enable documentation build (requires Doxygen, default: OFF)
cmake -DSVD_BUILD_DOCS=ON ..

# Build shared library instead of static (default: OFF)
cmake -DBUILD_SHARED_LIBS=ON ..
```

### Running the Example

After building, you can run the provided example:

```bash
# From the build directory
./examples/simple_exporter/simple_exporter          # Linux/macOS
.\examples\simple_exporter\Release\simple_exporter.exe  # Windows
```

This will create sample export files demonstrating the library's capabilities:
- `sample_export.json` - Complete vessel dataset in JSON format
- `sample_export.xml` - Same data in XML format  
- `sample_export.csv` - Tabular representation in CSV format

The example demonstrates:
- Creating and populating a complete SVD dataset
- Using all three export formats
- Proper error handling
- File I/O operations

## Usage

### Basic Example

```cpp
#include <svd/svd.hpp>
#include <svd/exporters/formats/svd_json_exporter.hpp>
#include <iostream>
#include <chrono>

int main() {
    // Create a dataset
    svd::models::StandardisedVesselDataset dataset;
    
    // Set general information
    auto& general = dataset.getGeneral();
    general.setShipName("Example Vessel");
    general.setImo("1234567");
    general.setShipReportingDate(std::chrono::system_clock::now());
    general.setEventType("Noon Report");
    general.setOperationType("Sailing");
    
    // Set port information
    auto& port = dataset.getPortAndRoute();
    port.setDeparturePortCode("USLAX");
    port.setArrivalPortCode("NLRTM");
    
    // Export to JSON
    svd::exporters::formats::SvdJsonExporter jsonExporter;
    auto result = jsonExporter.exportData(dataset);
    
    std::cout << "JSON Export:\n" << result << std::endl;
    
    return 0;
}
```

### Export Examples

```cpp
#include <svd/exporters/formats/svd_json_exporter.hpp>
#include <svd/exporters/formats/svd_xml_exporter.hpp>
#include <svd/exporters/formats/svd_csv_exporter.hpp>

// JSON Export
svd::exporters::formats::SvdJsonExporter jsonExporter;
std::string jsonResult = jsonExporter.exportData(dataset);

// XML Export
svd::exporters::formats::SvdXmlExporter xmlExporter;
std::string xmlResult = xmlExporter.exportData(dataset);

// CSV Export
svd::exporters::formats::SvdCsvExporter csvExporter;
std::string csvResult = csvExporter.exportData(dataset);

// Get suggested filename
std::string filename = jsonExporter.getSuggestedFilename(dataset);
```

### Validation

```cpp
#include <svd/validators/standardised_vessel_dataset_validator.hpp>

svd::validators::StandardisedVesselDatasetValidator validator;
auto validationResult = validator.validate(dataset);

if (!validationResult.isValid()) {
    for (const auto& error : validationResult.getErrors()) {
        std::cout << "Validation Error: " << error.getMessage() << std::endl;
    }
}
```

### Working with Files

```cpp
#include <fstream>

// Save to file
std::string jsonContent = jsonExporter.exportData(dataset);
std::string filename = jsonExporter.getSuggestedFilename(dataset);

std::ofstream file(filename);
if (file.is_open()) {
    file << jsonContent;
    file.close();
    std::cout << "Successfully wrote file: " << filename << std::endl;
} else {
    std::cerr << "Failed to write file: " << filename << std::endl;
}
```
    }
}
```

## Project Structure

```
cpp/
├── CMakeLists.txt              # Main CMake configuration
├── README.md                   # This file
├── .gitignore                  # Git ignore rules
├── cmake/                      # CMake configuration files
│   └── SvdConfig.cmake.in     # Package configuration template
├── include/svd/               # Public headers
│   ├── svd.hpp                # Main include file
│   ├── models/                # Model class headers
│   ├── exporters/             # Exporter class headers
│   └── validators/            # Validator class headers
├── src/svd/                   # Implementation files
│   ├── models/                # Model implementations
│   ├── exporters/             # Exporter implementations
│   └── validators/            # Validator implementations
├── examples/                  # Example applications
│   └── simple_exporter/       # Basic usage example
├── tests/                     # Test suite
│   ├── unit/                  # Unit tests
│   └── integration/           # Integration tests
└── docs/                      # Documentation
```

## Installation

### Using CMake Install

```bash
# Build and install
cmake --build . --target install

# Use in your project's CMakeLists.txt
find_package(svd REQUIRED)
target_link_libraries(your_target svd::svd)
```

### Manual Integration

You can also integrate the library directly into your project:

1. Copy the `include/` and `src/` directories to your project
2. Add the source files to your CMakeLists.txt:

```cmake
# Add the SVD library
add_subdirectory(path/to/svd)
target_link_libraries(your_target svd)
```

### Package Managers

Support for popular C++ package managers is planned:
- Conan (planned)
- vcpkg (planned)

### Using in Your Project

After installation, create a simple CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(svd REQUIRED)

add_executable(my_app main.cpp)
target_link_libraries(my_app svd::svd)
```

## Testing

The library includes comprehensive unit tests using GoogleTest:

```bash
# Run all tests
ctest --output-on-failure

# Run with specific configuration (Windows)
ctest -C Release --output-on-failure

# Run with verbose output
ctest --verbose

# Run specific test
ctest -R "SvdJsonExporterTest"
```

### Test Coverage

- **Model Tests**: Verify all model classes work correctly
- **Exporter Tests**: Test JSON, XML, and CSV export functionality
- **Validator Tests**: Ensure validation logic is working
- **Integration Tests**: End-to-end workflow testing

## Troubleshooting

### Common Issues

#### CMake Configuration Issues
```bash
# Clear CMake cache if having issues
rm -rf build/
mkdir build && cd build
cmake ..
```

#### Windows Compiler Warnings
The library may generate warnings about `gmtime` being unsafe on Windows. These are harmless and the code works correctly, but you can suppress them by adding:
```cpp
#define _CRT_SECURE_NO_WARNINGS
```

#### Missing Dependencies
All dependencies are fetched automatically. If you encounter network issues:
```bash
# Try with system proxy settings
cmake -DCMAKE_USE_SYSTEM_PROXY=ON ..
```

#### Build Errors
- Ensure your compiler supports C++20
- Check that CMake version is 3.20 or higher
- Verify you have sufficient disk space for dependencies (~100MB)

### Performance Tips

- Use Release build for production: `cmake --build . --config Release`
- The library is header-heavy; consider using precompiled headers for faster builds
- Link statically for better performance in most use cases

## Documentation

- API documentation is generated using Doxygen
- Examples are provided in the `examples/` directory
- See the C# implementation documentation for detailed SVD specification

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Submit a pull request

## License

This project follows the same license as the main Standardised Vessel Dataset project.

## Related Projects

- [C# Implementation](../dotnet/) - Original C# implementation
- [TypeScript Implementation](../typescript/) - TypeScript/JavaScript implementation

## Support

For questions and support, please refer to the main project repository or open an issue.
