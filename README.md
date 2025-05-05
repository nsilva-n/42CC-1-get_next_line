# get_next_line

*Oh intrepid coder, take up thy tools and enter the realm of infinite file reading!*

Within this repository lies the challenge of creating the legendary `get_next_line` function, a utility designed to read files line by line, regardless of their size or complexity.

## Prelude

*Oh seeker of knowledge, prepare thyself for the quest of `get_next_line`!*  

Here, you will master the intricacies of file handling, buffer management, and dynamic memory allocation, crafting a function that retrieves the next line from a file descriptor with elegance and efficiency.

## Table of Contents

- [The Quest](#the-quest)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Function Prototype](#function-prototype)
- [Testing](#testing)
- [Acknowledgments](#acknowledgments)

## The Quest

*Embark, O valiant coder, on this epic journey!*

Your mission is to implement the `get_next_line` function, adhering to the following requirements:
- Read from a file descriptor one line at a time until the end of the file is reached.
- Handle files of arbitrary size with a fixed-size buffer.
- Manage memory dynamically to ensure there are no leaks or overflows.
- Support multiple file descriptors simultaneously with grace.

This project is a rite of passage, a test of your ability to manage resources and think algorithmically.

## Features

*Witness the marvels of get_next_line:*

- **Line-by-Line Reading**: Retrieve each line from a file or input stream without consuming the entire file at once.
- **Dynamic Buffer Management**: Adapt to different buffer sizes with efficient memory handling.
- **Multi-Descriptor Support**: Handle multiple open file descriptors concurrently.
- **Customizable Buffer Size**: Define the buffer size using the `BUFFER_SIZE` macro.

## Requirements

*To achieve greatness, gather these provisions:*

- **Compiler**: GCC or Clang.
- **Libraries**: Standard C library (`<unistd.h>`, `<stdlib.h>`, `<fcntl.h>`).
- **Makefile**: Automate your build process with targets `all`, `clean`, `fclean`, and `re`.

## Getting Started

*Raise the anchor and set sail on your coding voyage!*

Clone this repository and navigate to the `get_next_line` directory:
```bash
git clone https://github.com/nsilva-n/42CC-1-get_next_line.git
cd 42CC-1-get_next_line
make
```

To include `get_next_line` in your projects, compile it alongside your files:
```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

## Function Prototype

*With this declaration, command the art of file reading:*
```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: The file descriptor to read from.

### Return Value
- Returns the next line read from the file descriptor, including the newline character, or `NULL` if the end of the file is reached or an error occurs.

### Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Testing

*Test thy creation to ensure its strength:*

Create your own test files to ensure correctness and edge-case handling. For example:
- Files with no newline characters.
- Files with extremely long lines.
- Empty files.
- Multiple open file descriptors.

Example:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);

    printf("File1: %s", line1);
    printf("File2: %s", line2);

    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
    return 0;
}
```

## Acknowledgments

*With gratitude to the authors of the C Standard Library and the 42 curriculum, we dedicate this work.*
May your journey through the labyrinth of `get_next_line` lead you to enlightenment and mastery over the art of file reading.
