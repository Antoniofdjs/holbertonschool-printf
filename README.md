# Holbertonschool-printf

## Description
This project aims to recreate the `printf` function in C.
It will handle some basic cases.


#Content
- [Overview](#overview)
- [Features](#features)
- [Use](#use)
- [Examples](#examples)
- [Authors](#authors)
- [Resources](#resources)


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
## Examples

Example of using the _printf function:

```C
#include "main.h"

int main() {

  char str = "there"
  _printf("Hello %s, str);

  return (0);
}
```
output:

```c
Hello there
```
## Authors

- [Louis Toro](https://github.com/Ltoro9)
- [Antonio De Jesus](https://github.com/Antoniofdjs)


# Resources
- [Secrets_of_printf](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2022/11/d38f88e96a617135804dca9f9c49632751e06aa7.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231122%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231122T035956Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=44a20cfee8d60cac7e89bcbe8274e1b20fc444e84d1c209375ba82190128e183)
