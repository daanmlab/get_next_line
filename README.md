# 📖 get_next_line

## 🚪 Welcome to Line-by-Line Adventures!
Hey there! Dive into `get_next_line`, where reading text files in C becomes an exciting journey. Ready to learn how to fetch lines from a file? Let's go!

## 💡 So, What's the Big Idea?
`get_next_line` is our deep dive into file reading in C. Your mission, should you choose to accept it, is to create a function that reads a line from a file or any input source, stopping at the end of each line. It's a fantastic way to up your C game!

## 🛠️ Prerequisites
A bit familiar with C, especially file operations and memory management? Perfect – that's all you need to get started!

## 🌟 How to Get Started
Grab the code and get your hands dirty:
```bash
git clone https://github.com/daanmlab/get_next_line.git
```
To compile, you can use `gcc`. For example:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o get_next_line
```
Adjust `BUFFER_SIZE` as needed for your testing or usage.

## 📚 What's Inside?
`get_next_line` features a neat function for reading lines from file descriptors. Whether it's files, standard input, or other sources, this function's got you covered.

## 📝 Sample Usage
Here’s a taste of how it works:
```c
#include "get_next_line.h"

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
---
