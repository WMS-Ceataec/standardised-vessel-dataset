# Standardised Vessel Dataset

A Python implementation of the Standardised Vessel Dataset, providing a modern, type-safe, and efficient way to work with vessel data.

## Features

- Full type safety with Python 3.10+ type hints
- Pydantic models for data validation
- Comprehensive test coverage
- Modern Python packaging with pyproject.toml
- CSV import/export support
- Data validation and standardization

## Installation

```bash
pip install standardised-vessel-dataset
```

## Quick Start

```python
from standardised_vessel_dataset import StandardizedVesselDataset

# Create a new dataset
dataset = StandardizedVesselDataset()

# Load data from CSV
dataset.load_from_csv("vessel_data.csv")

# Access vessel information
vessel_info = dataset.general_information
cargo_info = dataset.cargo_information

# Export to CSV
dataset.export_to_csv("standardized_data.csv")
```

## Development

1. Clone the repository
2. Install development dependencies:
   ```bash
   pip install -e ".[dev]"
   ```
3. Run tests:
   ```bash
   pytest
   ```
4. Run type checking:
   ```bash
   mypy .
   ```
5. Run linting:
   ```bash
   ruff check .
   ```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Run tests and linting
5. Submit a pull request

## License

This project is licensed under the terms of the LICENSE file included in the repository.
