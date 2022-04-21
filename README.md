# systems-project
A project for a university course

## my-cat
Reads the given files and outputs the contents to *stdout*.
```
Usage: ./my-cat file1 [file2 ...]

Example: ./my-cat file1.txt
```
### Requirements
- [X]   Reads a file as specified by the user and prints its contents
- [X]   Can be used with multiple files on the command line and print out each file in order.
- [X]   In all non-error cases, my-cat should exit with status code 0
- [X]   If no files are specified on the command line, my-cat should just exit and return 0
- [X]   If fopen() fails, it should print the exact message "my-cat: cannot open file" (followed by a newline) and exit with status code 1.
- [X]   If multiple files are specified on the command line, the files should be printed out in order until the end of the file list is reached or an error opening a file is reached (at which point the error message is printed and my-cat exits).

## my-grep
Searches the given searchterm from the given files and prints the lines containing the term to *stdout*.
```
Usage: ./my-cat searchterm [file ...]

Example: ./my-grep file1.txt file.c
```
### Requirements
- [X]   Searches for case sensitive search terms from a file or stdin. If matches are found it prints the lines which has them.
- [X]   Works with multiple files given as arguments.
- [X]   If no file is given searches from user input.
- [X]   Prints errors if there are no arguments or file open fails and exits with status 1.
- [X]   If search string is empty, all lines are matched.
- [X]   Works even with very long lines.
- [X]   In all other cases, my-grep should exit with return code 0.         // toimiiko jos pitää crtl+c?

## my-zip
Performs simple run-length encoding on the given files and outputs the results to stdout. *It is recommended to redirect the results to a separate file. Example below.* __Note that if given multiple files they will be compressed into one output file!__
```
Usage: ./my-zip file1 [file2 ...]

Example: ./my-zip file1.txt file2.txt > file.z
```
### Requirements
- [X]   Outputs to stdout
- [X]   Outputs 5 byte chunks consisting of 4 bytes of integer binary and 1 character
- [X]   Works with an multiple argument files
- [X]   Prints usage and exits with 1 when no arguments are given

## my-unzip
Unzips files encoded with *my-zip* and redirects the results to stdout. *It is recommended to redirect the results to a separate file. Example below.*
```
Usage: ./my-zip file1 [file2 ...]

./my-unzip file.z > output.txt
```
### Requirements
- [X]   Outputs to stdout
- [X]   Reads the format from my-zip
- [X]   Works with an multiple argument files
- [X]   Prints usage and exits with 1 when no arguments are given
