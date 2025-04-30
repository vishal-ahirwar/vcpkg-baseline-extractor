

# vcpkg-baseline-extractor

**vcpkg-baseline-extractor** is a lightweight tool to extract the baseline version of a package from the [vcpkg](https://github.com/microsoft/vcpkg) repository.

This tool allows you to easily query and retrieve the exact version (baseline) of any package as specified in `baseline.json` from vcpkg's official ports.

---

## Features

- Extracts the baseline version of a package.
- Simple command-line usage.
- Fast and lightweight (written in C++).
- Useful for automation scripts or custom dependency managers.

---

## How It Works

The tool parses the `baseline.json` file from a vcpkg repository or directory to find and print the baseline version of the specified package.

---

## Usage

```bash
vcpkg-baseline-extractor <path-to-vcpkg-root> <package-name>
```

### Arguments
- `<package-name>`: Name of the package whose baseline version you want to extract.

## Building

You can build the project using CMake:

```bash
git clone https://github.com/vishal-ahirwar/vcpkg-baseline-extractor.git
cd vcpkg-baseline-extractor
mkdir build
cd build
cmake ..
cmake --build .
```
or
```
aura build
```
This will generate the executable in the `build/` directory.

---

## Requirements

- C++23 compatible compiler (e.g., Clang, GCC, MSVC)
- CMake 3.15+
- (Optional) Ninja for faster builds
- vcpkg
---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contribution

Contributions, issues, and feature requests are welcome!  
Feel free to open an issue or a pull request.

---
