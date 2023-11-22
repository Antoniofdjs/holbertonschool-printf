# Holbertonschool-printf

## Description
This project aims to recreate the `printf` function in C.
It will handle some basic cases.


#Content
- [Overview](#overview)
- [Features](#features)
- [Use](#use)


## Overview
The function `_printf` will replicate and handle some of the basic case specifiers from the C printf function and some advanced like hexa decimal, octal, and address conversions.

## Features
**Basic Format Specifiers**: Currently supports `%s` (strings), `%c` (characters), and `%d` `%i` (integers).


**More Format Specifiers**: Supports `%x` `%X` (hexadecimal),`%u` (unsigned integers), `%o` (octal).

## Use
Include all the files present in the repository. 

``my_printf.c`` --- Contains `_printf` function.

``main.h`` --- All necessary headers and prototypes.

`num_functions.c` --- Has all functions that handle number cases.

`char_funtcions.c` --- Has all functions that handle character cases.


Once you have all files remember to include `main.h` in your `.c` file :

```c
#include "main.h"

```
To use the function simply call it by giving a format string with case specifiers and can be followed by arguments like this :

```c
int total_len = _printf("Hello %s I am %d years old \n", "there", 1000);
_printf("Total characters printed: %d\n", total_len);
```
