# PyObject Example

This project demonstrates a simple implementation of Python-like objects in C, including reference counting and object reuse. The project includes the following key features:
- Base `PyObject` structure
- Integer (`PyIntObject`) and string (`PyStrObject`) objects
- Reference counting
- Global registry to reuse objects
- Functions for creating, reassigning, and managing objects

## Overview

The project consists of the following files:
- `pyobject.h`, `pyint.h`, `pystr.h`: Header file containing the structure definitions and function declarations.
- `pyobject.c`, `pyint.c`, `pystr.c`: Source file with the implementation of the functions declared in the header file.
- `main.c`: Main program demonstrating the creation, reassignment, and management of `PyIntObject` and `PyStrObject` objects.

## Files

### `pyobject.h`

Defines the base `PyObject` structure and derived structures for integers and strings. Declares functions for reference counting, creating, printing, and deallocating objects. Also includes functions for reassigning objects.

### `pyobject.c`

Implements the functions declared in the header file, including:
- Reference counting (`Py_INCREF`, `Py_DECREF`)
- Creating new objects (`PyInt_Create`, `PyStr_Create`)
- Printing objects (`PyInt_Print`, `PyStr_Print`)
- Deallocating objects (`PyInt_Dealloc`, `PyStr_Dealloc`)
- Reassigning objects (`Reassign_IntObject`, `Reassign_StrObject`)
- Managing a global registry of objects

### `main.c`

Demonstrates the use of the custom `PyObject` implementation:
- Creating and printing integer and string objects
- Reassigning objects with new values
- Managing reference counts and ensuring proper deallocation

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection) or any other C compiler

### Building the Project

To compile the project, use the following command:

```sh
gcc -o pyobject_example main.c pyobject.c
