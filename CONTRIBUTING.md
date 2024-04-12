# Contribution Guidelines

Thank you for considering contributing to this library! We appreciate your interest and welcome contributions from the community.

## How to Contribute

### Reporting Bugs

If you come across a bug or unexpected behavior, please open an issue on our GitHub repository. Provide detailed information about the bug, including steps to reproduce it and your environment details.

### Feature Requests

We welcome ideas for new features or enhancements. If you have a suggestion, please open an issue on our GitHub repository with a clear description of the proposed feature.

### Pull Requests

We encourage contributions through pull requests (PRs). To contribute code, follow these steps:

1. Create an issue on our GitHub repository. The **issue ID must be bound with the branch name and PR title**.
1. Fork the repository to your GitHub account.
2. Clone the forked repository to your local machine.
3. Create a dedicated branch. See branch naming convention below.
4. Push your code and open a pull request, providing a brief explanation of your changes. 
We follow the Conventional Commits specification for our PR titles. Conventional Commits provide a standardised convention for writing commit messages, making it easier to understand the history of your project and automate the versioning process.

Here some examples of valid PR titles:
- `feat(1): add new exporter`
- `fix(1): fix issue on custom exporter`
- `ci(1): update dotnet build pipeline`

For more information on Conventional Commits, refer to [Conventional Commits Specification](https://www.conventionalcommits.org/en/v1.0.0/).

### Breaking Changes:

Mention the breaking changes if you have made in PR title and describe same in PR description.

Here some examples of valid PR titles with Breaking Changes:
- `feat(1)!: rename base exporter`
- `fix(1)!: dependency updated`

### Branching naming convention

When creating branches for your contributions, please follow a clear and descriptive naming convention. This helps in identifying the purpose of the branch and makes collaboration more effective.

Here some examples of valid branch naming bounded to a GitHub issue ID:

- `feature/1-add a new exporter`
- `fix/1-fix-exported-data`
- `ci/1-update-build-pipeline`

### Coding Guidelines

- Follow the existing coding style and conventions in the project.
- Write clear and concise code with appropriate comments where necessary.
- Ensure your code follows the best practices of software development, including maintainability and testability.

### Testing

- Write tests for new features or modifications to existing features.
- Ensure that all tests pass before submitting a pull request.
- Keep the code coverage on at least 80%.

Thank you for contributing!
