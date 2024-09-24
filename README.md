# get_next_line

### Overview

get_next_line is a function that reads from a file descriptor line by line. It handles different file formats and inputs, ensuring that each call to get_next_line retrieves the next line from the file. The implementation is efficient, using static variables and linked lists to manage and store chunks of the file. The function prototype is `char *get_next_line(int fd)`.

### Features

- Buffered Reading: Uses a buffer to read the file in chunks, reducing the number of system calls and improving performance.
- Linked List Management: The function dynamically manages memory using a linked list to store chunks of the file until a newline is encountered.
- Static Variables: Static variables ensure that multiple calls to get_next_line continue reading from where the previous call left off.

### How It Works

1. Buffering: The function uses a buffer of BUFFER_SIZE to read the file in chunks.
2. Line Parsing: As the buffer is filled, the function checks for newline characters (`\n`) to determine where a line ends. It continues reading until a full line is identified or the file ends.
3. Dynamic String Management: Each part of the file read from the buffer is stored in a linked list. Once a full line is identified, the function concatenates the parts to return the entire line as a single string.
4. Static Variables: The buffer and position are declared as static variables, allowing the function to retain state between multiple calls to handle files larger than the buffer size.

### Error Handling

- If a read error occurs, the function frees any allocated memory and returns NULL.
- Handles incomplete lines at the end of the file by checking for null-terminators and adjusting buffer size accordingly.
