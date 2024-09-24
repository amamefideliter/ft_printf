#ft_printf

### Description

The `ft_printf` project is a recoding of the standard C `printf` function. This custom implementation replicates the functionality of `printf` by processing format strings and variadic arguments, handling various specifiers such as characters, strings, pointers, integers, and hexadecimal values. Function prototype is `int ft_printf(const char *format, ...)`.

### Key Features

Supports the following conversion specifiers:\
- `%c` for characters
- `%s` for strings
- `%p` for pointers
- `%d` / `%i` for integers
- `%u` for unsigned integers
- `%x` / `%X` for hexadecimal values (lowercase and uppercase)
-  `%%` for printing a literal percent sign

### Code Structure

#### Main Function
The core function iterates through the format string. When it encounters a `%` symbol, it checks the next character to determine the specifier and processes the corresponding argument using the helper function parse_specifier.
#### Helper Functions

- `parse_specifier`: This function identifies the specifier and calls the appropriate printing function for handling that specific type (e.g., characters, integers, strings, etc.).
- `ft_print_*`: These are the helper functions responsible for printing specific data types, such as characters, integers, unsigned numbers, and hexadecimal values.

### Edge Cases Handled

- Properly handles invalid or unsupported format specifiers.
- Allows printing of a literal % character with %%.
- Manages various data types and properly handles conversion to string format before output.
