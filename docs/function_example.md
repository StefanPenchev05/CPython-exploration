# Function Registry

This folder contains an implementation of a simple function registry in C, which allows defining, storing, and calling functions dynamically by name. This mimics the behavior of Python's `def`.

## Overview

The project demonstrates the following key features:
- Defining functions using function pointers.
- Storing functions in a registry.
- Looking up and calling functions by name.

## Files

- `functions.h`: Header file containing the structure definitions and function declarations.
- `functions.c`: Source file with the implementation of the functions declared in the header file.
- `main.c`: Main program demonstrating the creation, registration, and calling of functions.
- `README.md`: This file, providing an overview and instructions.

## Usage

### Prerequisites

- GCC (GNU Compiler Collection) or any other C compiler.

### Building the Project

To compile the project, navigate to the `function_registry` folder and use the following command:

```sh
gcc -o function_registry main.c functions.c
