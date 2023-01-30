# ft_printf
Because `ft_putnbr()` and `ft_putstr() aren’t enough.

A custom implementation of the C library function `printf()` in C.

Grade: 100/100

### Features
This implementation supports the following conversion specifications:

- `%c` - Single character
- `%s` - String of characters
- `%p` - Pointer address
- `%d` and `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` and `%X` - Unsigned hexadecimal integer (lowercase and uppercase respectively)
- `%%` - Literal % character

### Usage
This implementation can be used in the same way as `printf()`.

```
#include "ft_printf.h"

int main(void) {
    ft_printf("This is a string: %s\n", "Hello, World!");
    ft_printf("This is a number: %d\n", 42);
    return 0;
}
```
### Implementation
The `ft_printf()` function takes a string as its first argument and additional arguments as required by the conversion specifications in the string.

The function uses the `va_start()`, `va_arg()` and `va_end()` macros to handle the variable argument list. The `ft_parseargs()` function takes a character representing the conversion specification and the `va_list` as arguments, and returns the number of characters written to standard output.

The supported conversion specifications are processed through functions such as `ft_putchar()`, `ft_putstr()` and `ft_putptr()` that write the output to standard output.
