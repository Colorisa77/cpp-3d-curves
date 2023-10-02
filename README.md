# 3D Curves

This repository contains two programs: one that performs various tasks related to 3D geometry, and another one that utilizes a dynamic library named `3d-curves` for specific computational operations.

## Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [Building](#building)

## Description

`3D Curves` is a versatile C++ program designed to handle a variety of tasks related to 3D geometry. It provides classes and functions for working with 3D curves, including circles, ellipses, and helixes. Additionally, the repository includes a separate program, `3d-curves-with-dynamic-lib`, which demonstrates how to utilize the `3d-curves` dynamic library for specific computational tasks on Linux.

## Features

- **3D Curve Calculations:** The program supports calculations for various 3D curves, including circles, ellipses, and helixes.
- **Dynamic Library Usage (Linux):** The `3d-curves-with-dynamic-lib` program showcases the integration of the `3d-curves` dynamic library for specialized operations on Linux.
- **Error Handling:** Proper error handling and exception mechanisms are implemented to ensure robust execution.

## Requirements

- **CMake 3.22:** Make sure you have CMake version 3.22 or higher installed. You can download it from [CMake's official website](https://cmake.org/download/).
- **C++17:** The codebase uses C++17 features, so a compatible C++ compiler is required.
- **IDE:** The work is done using CLion IDE.

## Usage

To use the `3D Curves` program and the dynamic library, follow these steps:

1. Clone the repository: `git clone https://github.com/Colorisa77/3d-curves.git`
2. Build the project: `cd 3d-curves && cmake . && cmake --build .`

For the `3d-curves-with-dynamic-lib` program, additional steps are required:

1. Navigate to the `3d-curves-with-dynamic-lib` directory: `cd 3d-curves-with-dynamic-lib`
2. Build the project using the same steps as above.

## Building

To build the programs, follow the requirements specified above and then run:

1. Install CMake 3.22 or higher.
2. Run CMake to generate build files: `cmake .`
3. Build the project: `cmake --build .`