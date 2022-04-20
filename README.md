# systems-project

- reads a file as specified by the user and prints its contents
- can be used with multiple files on the command line and print out each file in order.
- all non-error cases, my-cat should exit with status code 0
- If no files are specified on the command line, my-cat should just exit and return 0
- If fopen() fails, it should print the exact message "my-cat: cannot open file" (followed by a newline) and exit with status code 1.
- If multiple files are specified on the command line, the files should be printed out in order until the end of the file list is reached or an error opening a file is reached (at which point the error message is printed and my-cat exits).