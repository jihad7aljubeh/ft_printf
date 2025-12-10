# ft_printf

`ft_printf` is a custom implementation of the standard C `printf` function, developed as part of the 42 curriculum.

This project focuses on:

- Variadic functions (`stdarg.h`)
- Parsing format strings
- Printing and formatting different data types
- Handling edge cases and undefined behaviors
- Writing clean and modular C code that respects the 42 Norme

---

## 📚 Table of Contents

- [Overview](#overview)
- [Function Prototype](#function-prototype)
- [Supported Conversions](#supported-conversions)
- [Behavior](#behavior)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Usage](#usage)
- [Examples](#examples)
- [Norme & Constraints](#norme--constraints)
- [Testing](#testing)
- [Author](#author)

---

## Overview

The goal of **ft_printf** is to recreate the behavior of `printf` with a subset of its features.

Your function should:

- Print formatted output to the standard output (`stdout`).
- Return the total number of characters printed (excluding the null terminator).
- Mimic the behavior of the original `printf` for the implemented conversions as closely as possible.

---

## Function Prototype

```c
int ft_printf(const char *format, ...);
```

- `format` – a C-string that contains the text to be written to stdout, optionally including format specifiers starting with `%`.
- `...` – a variable number of arguments depending on the format string.

---

## Supported Conversions

According to the **ft_printf** subject, the following conversions must be supported:

- `%c` – Character
- `%s` – String
- `%p` – Pointer address (in hexadecimal, with `0x` prefix)
- `%d` – Signed decimal integer
- `%i` – Signed decimal integer (same as `%d`)
- `%u` – Unsigned decimal integer
- `%x` – Unsigned hexadecimal integer (lowercase)
- `%X` – Unsigned hexadecimal integer (uppercase)
- `%%` – Print a literal `%` character

> If you added extra flags/width/precision for your own learning, the core behavior should still match the subject’s requirements for evaluation.

---

## Behavior

- The function **prints** to file descriptor `1` (standard output).
- It **returns** the total number of characters printed.
- In case of an internal error (e.g. write failure), the common approach is to return `-1` or handle it according to your design (as long as it’s consistent).

Example:

```c
int len;

len = ft_printf("Hello %s! Number: %d\n", "world", 42);
// Output: Hello world! Number: 42
// len == 26 (for example, depending on exact string)
```

---

## Project Structure

Typical `ft_printf` repository layout:

```text
.
├── ft_printf.c
├── ft_printf.h
├── src/
│   ├── ft_print_char.c
│   ├── ft_print_string.c
│   ├── ft_print_pointer.c
│   ├── ft_print_number.c
│   ├── ft_print_unsigned.c
│   ├── ft_print_hex.c
│   └── ft_utils.c
├── libft/                # if you reuse your libft (optional)
├── Makefile
└── README.md
```

- **`ft_printf.c`** – Main function, parsing loop, dispatching to helper functions.
- **`ft_printf.h`** – Prototypes and necessary includes (`<stdarg.h>`, `<unistd.h>`, maybe `<stdlib.h>`).
- **`src/`** – Helper functions for each conversion (your exact naming may differ).
- **`libft/`** – Optional: if your implementation uses your own `libft` functions.

> If your layout or filenames differ, you can adjust this section to match your project.

---

## Compilation

If you are building **ft_printf** as a library:

```bash
make
```

This usually generates:

```text
libftprintf.a
```

You can then link it in other projects:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
```

If your `Makefile` already handles a test binary, simply run:

```bash
make
./test_printf
```

---

## Usage

### In your own project

1. **Include the header**:

   ```c
   #include "ft_printf.h"
   ```

2. **Compile and link** with `libftprintf.a` (or directly with your `.c` files):

   ```bash
   cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
   ```

3. Use `ft_printf` just like `printf` (within the supported conversions).

---

## Examples

### Basic usage

```c
#include "ft_printf.h"

int main(void)
{
    int len1;
    int len2;

    len1 = ft_printf("Hello %s!\n", "world");
    len2 = ft_printf("Decimal: %d, Hex: %x\n", 42, 42);

    ft_printf("Printed %d chars in first call\n", len1);
    ft_printf("Printed %d chars in second call\n", len2);
    return (0);
}
```

### Printing pointers and percent sign

```c
#include "ft_printf.h"

int main(void)
{
    int     x = 123;
    void    *ptr = &x;

    ft_printf("Address of x: %p\n", ptr);
    ft_printf("Print 100%% done!\n");
    return (0);
}
```

---

## Norme & Constraints

- Must respect the **42 Norme**.
- No memory leaks.
- No forbidden functions (only those allowed in the subject).
- You must use `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` to handle the variable arguments.
- Behavior should be as close as possible to the original `printf` for the implemented conversions.

---

## Testing

You can:

- Write your own `main.c` with many cases:
  - Edge values (`INT_MIN`, `INT_MAX`, `0`, negative numbers)
  - Empty strings, long strings
  - `NULL` pointers and `NULL` strings (how you handle them should be consistent, usually printing `(null)`).
- Compare outputs and return values directly with the real `printf`:

  ```c
  #include <stdio.h>
  #include "ft_printf.h"

  int main(void)
  {
      int r1 = printf("   printf: %d\n", -42);
      int r2 = ft_printf("ft_printf: %d\n", -42);

      printf("   printf printed %d chars\n", r1);
      printf("ft_printf printed %d chars\n", r2);
      return (0);
  }
  ```

- Use community testers by searching GitHub for:
  - `ft_printf_tester`
  - `printf_42_tester`
  - etc.

---

## Author

- **Login:** `jalju-be`  
- **School:** 42  
- **GitHub:** [jihad7aljubeh](https://github.com/jihad7aljubeh)
