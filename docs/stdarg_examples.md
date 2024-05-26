# Understanding `stdarg.h`

`stdarg.h` is a header file in the C standard library that provides macros for handling functions with a variable number of arguments. This is particularly useful for creating flexible functions such as `printf` and `scanf`.

## Key Components of `stdarg.h`

`stdarg.h` defines four main macros for managing variable argument lists:

1. **`va_list`**: A type to hold information needed to retrieve additional arguments.
2. **`va_start`**: A macro to initialize a `va_list` variable to be used with `va_arg`.
3. **`va_arg`**: A macro to retrieve the next argument in the parameter list of the function with the specified type.
4. **`va_end`**: A macro to clean up the `va_list` variable after processing the arguments.

### Detailed Explanation of the Macros

#### `va_list`
- **Definition**: `va_list` is a type suitable for holding information needed by `va_start`, `va_arg`, and `va_end` macros.
- **Usage**: It is declared before accessing the variable arguments.
    ```c
    va_list args;
    ```

#### `va_start`
- **Definition**: `va_start` macro initializes the `va_list` variable to point to the first argument in the variable argument list.
- **Parameters**:
  - `ap`: A `va_list` object to initialize.
  - `last`: The name of the last fixed parameter (i.e., the parameter before the ellipsis `...`).
- **Usage**: Called before retrieving the arguments.
    ```c
    va_start(args, last_fixed_param);
    ```

#### `va_arg`
- **Definition**: `va_arg` macro expands to an expression that retrieves the next argument in the parameter list of the function.
- **Parameters**:
  - `ap`: A `va_list` object initialized by `va_start`.
  - `type`: The type of the next argument to retrieve.
- **Usage**: Called to retrieve each argument in the list.
    ```c
    int value = va_arg(args, int);
    ```

#### `va_end`
- **Definition**: `va_end` macro ends the traversal of the variable argument list started by `va_start`.
- **Parameters**:
  - `ap`: A `va_list` object that was previously initialized by `va_start`.
- **Usage**: Called to clean up the `va_list` object.
    ```c
    va_end(args);
    ```

### Examples of Using `stdarg.h`

#### Example 1: Simple Variadic Function

Let's start with a simple example to sum a variable number of integers.

**File: `src/c_examples/stdarg_examples/simple_variadic.c`**
```c
#include <stdio.h>
#include <stdarg.h>

// Function to calculate the sum of a variable number of integers
int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main() {
    printf("Sum of 1, 2, 3: %d\n", sum(3, 1, 2, 3));
    printf("Sum of 5, 10, 15: %d\n", sum(3, 5, 10, 15));
    return 0;
}
```