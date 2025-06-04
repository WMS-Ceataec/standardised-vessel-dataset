# Standardised Vessel Dataset library 

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE)
[![NuGet](https://img.shields.io/nuget/v/Standardised.Vessel.Dataset)](https://www.nuget.org/packages/Standardised.Vessel.DataSet)
[![NPM](https://img.shields.io/npm/v/standardised-vessel-dataset)](https://www.npmjs.com/package/standardised-vessel-dataset)
[![C++](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](src/cpp)

## Introduction

Through a consortium of council members, the [Smart Maritime Network](https://smartmaritimenetwork.com/) has developed a living “Standardised Vessel Dataset” definition to help with finding a common way to collect and report data regarding all vessels sailing the seas.
The Maritime industry has complex ownership and management structures with vastly varying strategies on how to collect data on board vessels and this leads to vastly differing and very inefficient processes that require reporting or access to data.
Finding common standards is key to the improved efficiency of maritime operations and the Smart Maritime Network is helping find some of these standards with their council members.


This is an open-source library designed to wrap around and provide additional functionality related to the [Standardised Vessel Dataset for Noon Reports developed by the Smart Maritime Network](https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/). The primary purpose of this library is to typify the model, validate and export data to various output formats such as XML, CSV, or JSON (see features table below).

We will continue to grow this library over time as the SVD dataset is updated by the Smart Maritime Network and also as we develop further functionality that's useful for others.

We invite everyone to contribute to this library and you can see more details below on how to contribute or get in contact with the team.

## Language Support

This library provides implementations in multiple programming languages to support diverse development environments:

- **C++20**: Modern C++ implementation with comprehensive testing, smart pointer memory management, and cross-platform CMake build system
- **.NET Core**: Full-featured .NET implementation with extensive validation and export capabilities  
- **TypeScript**: Type-safe JavaScript implementation for web and Node.js environments


## Installation

Supports several different programming languages. For each programming
language, you can find instructions in the corresponding source directory:

| Language                             | Source                                                      |
|--------------------------------------|-------------------------------------------------------------|
| C++                                  | [src/cpp](src/cpp)                                         |
| .NET Core                            | [src/dotnet](src/dotnet)                                   |
| TypeScript                           | [src/typescript](src/typescript)                           |

## Features

| Feature                                         | C++       | .NET Core | TypeScript |
| ----------------------------------------------- | :-------: | :-------: | :---------: |
| Typified StandardisedVesselDataset (SVD) models |     ✅     |     ✅     |     ✅      |
| Validation of SVD input data                    |     ✅     |     ✅     |            |
| Export of data to XML, CSV, or JSON formats     |     ✅     |     ✅     |            |

## Supported Output formats
- XML
- CSV
- JSON

## Contributing
We welcome contributions! If you'd like to contribute to this library, please check out our contribution [guidelines](./CONTRIBUTING.md).

## License
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## Acknowledgments
The foundational design of the Standardised Vessel DataSet (SVD) model was crafted by Smart Maritime Network. Ceateac, a company within the Wilhelmsen Group, has developed this library as an initial version. We anticipate continuous iterative development and improvement to enhance its functionality and features.

## Contact

For any questions or feedback, feel free to reach out to us at [Slack](https://ceataeccommunity.slack.com/archives/C06KV6336UF).