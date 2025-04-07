# swiss_knife
A standard library extension for c++ to include some of the popular algorithms.

Here's a comprehensive **Markdown guide** for collaborators to clone your repository and run tests:

# Swiss Knife Development Guide

This guide explains how to set up the development environment and run tests for the Swiss Knife project.

## Prerequisites

- Git
- CMake (≥ 3.14)
- C++ compiler (GCC/Clang/MSVC)
- Make (GNU Make or equivalent)

## Getting Started

### 1. Clone the Repository

```bash
git clone --recursive https://github.com/CodeGeek2006/swiss_knife.git
cd swiss_knife
```

> **Important**: The `--recursive` flag ensures GoogleTest submodule is downloaded

### 2. Build the Project

```bash
make build
```

This will:
1. Create a `build` directory
2. Configure CMake
3. Compile all sources

> **Important**: Useless, you only need `make test` to test new feature, added for you to have a notion of how projects should be organized

## Running Tests

### Basic Tests

```bash
make test
```

This will:
1. Rebuild the project (if needed)
2. Run all tests through CTest
3. Show summary output

### Verbose Tests (Detailed Output)

```bash
make test-verbose
```

This will:
1. Rebuild the project
2. Run tests directly with colorful output
3. Show full test details (no output truncation)
4. Disable exception catching (helps with debugging)

## Common Workflows

### Normal Development Cycle

```bash
# After making changes:
make test       # Quick verification
make test-verbose  # If you need details
```

### Clean Rebuild

```bash
make clean      # Remove all build artifacts
make test       # Fresh rebuild and test
```

## Troubleshooting

### If tests fail

1. Check for compiler errors during build
2. Run `make test-verbose` for detailed output
3. Ensure all submodules are updated:
   ```bash
   git submodule update --init --recursive
   ```

### Platform-Specific Notes

- **Windows**: Requires Visual Studio or MinGW
- **macOS**: May need Xcode command line tools
- **Linux**: Ensure build-essential is installed

## CI Pipeline

Tests automatically run on:
- Every push to any branch
- Every pull request to `main`

View results in GitHub Actions tab.

## Need Help? - Cry

Kidding, contact [legend himself]('t.me/shiroyash_a') in Telegram
