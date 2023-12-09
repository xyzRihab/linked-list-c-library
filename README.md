# Linked List Library in C

This is a simple implementation of a linked list library in C, providing various operations for managing and manipulating linked lists. The library is designed with a focus on functional programming concepts, offering functions for insertion, deletion, searching, and more.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Description](#description)
- [Examples](#examples)
- [License](#license)

## Features

- Customized linked list implementation in C.
- Functional programming concepts: higher-order functions like `map`, `filter`, and `foldl`.
- Employs recursion extensively across various functions reducing overall complexity.
- Operations include insertion, deletion, searching, and more.

## Usage

To use this linked list library in your C project, follow these steps:

1. Include the `lists.h` header file in your project.
2. Compile the `lists.c` file along with your project.

## Description
1. `lists.h` file contains the different prototypes of the functions defined in this repo.
2. `lists.c` file contains the implementation of the functions.

## Examples

```c
#include "lists.h"

int main() {
    // Convert an integer to a linked list
    int number = 12345;
    Node numList = from_number(number);

    // Print the linked list
    printf("Linked List: ");
    // Implement your custom printing function instead of print_int
    print_list(numList, print_int, true);

    return 0;
}
```

## Licence
Copyright (c) 2023 [xyzRihab](https://github.com/xyzRihab)
