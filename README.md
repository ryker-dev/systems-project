# systems-project
A project for a university course.
All the programs were programmed on Ubuntu 20.04.4 LTS and were built for GNU/Linux usage.

## Compling the files
Use GCC to compile the source files into executables.
```
Examples:   gcc my-cat.c -o my-cat -Wall -Werror
            
            gcc my-zip.c -o my-zip -Wall -Werror

            . . .
```

# my-cat
Reads the given files and outputs the contents to *stdout*.
```
Usage:      ./my-cat file1 [file2 ...]

Example:    ./my-cat file1.txt
```

# my-grep
Searches the given searchterm from the given files and prints the lines containing the term to *stdout*.
```
Usage:      ./my-cat searchterm [file ...]

Example:    ./my-grep file1.txt file.c
```

# my-zip
Performs simple run-length encoding on the given files and outputs the results to stdout. *It is recommended to redirect the results to a separate file. Example below.* __Note that if given multiple files they will be compressed into one output file!__
```
Usage:      ./my-zip file1 [file2 ...]

Example:    ./my-zip file1.txt file2.txt > file.z
```

# my-unzip
Unzips files encoded with *my-zip* and redirects the results to stdout. *It is recommended to redirect the results to a separate file. Example below.*
```
Usage:      ./my-zip file1 [file2 ...]

Example:    ./my-unzip file.z > output.txt
```

# reverse
Reverses the given file. If an argument the program will use are given the program will use *stdin* and *stdout* for input and output respectively.
```
Usage:      ./reverse input output

Example:    ./reverse
            ./reverse input.txt
            ./reverse input.txt output.txt
```

# Requirements
### my-cat
- [X]   Reads a file as specified by the user and prints its contents
- [X]   Can be used with multiple files on the command line and print out each file in order.
- [X]   In all non-error cases, my-cat should exit with status code 0
- [X]   If no files are specified on the command line, my-cat should just exit and return 0
- [X]   If fopen() fails, it should print the exact message `my-cat: cannot open file` (followed by a newline) and exit with status code 1.
- [X]   If multiple files are specified on the command line, the files should be printed out in order until the end of the file list is reached or an error opening a file is reached (at which point the error message is printed and my-cat exits).

### my-grep
- [X]   Searches for case sensitive search terms from a file or stdin. If matches are found it prints the lines which has them.
- [X]   Works with multiple files given as arguments.
- [X]   If no file is given searches from user input.
- [X]   Prints errors if there are no arguments or file open fails and exits with status 1.
- [X]   If search string is empty, all lines are matched.
- [X]   Works even with very long lines.
- [X]   In all other cases, my-grep should exit with return code 0.

### my-zip
- [X]   Outputs to stdout
- [X]   Outputs 5 byte chunks consisting of 4 bytes of integer binary and 1 character
- [X]   Works with an multiple argument files
- [X]   Prints usage and exits with 1 when no arguments are given

### my-unzip
- [X]   Outputs to stdout
- [X]   Reads the format from my-zip
- [X]   Works with an multiple argument files
- [X]   Prints usage and exits with 1 when no arguments are given

### reverse
- [X]   If the input file and output file are the same file, you should print out an error message `Input and output file must differ` and exit with return code 1.
- [X]   You may not assume anything about how long a line should be. Thus, you may have to read in a very long input line...
- [X]   You may not assume anything about the length of the file, i.e., it may be VERY long.
- [X]   If the user specifies an input file or output file and opening any of the them fails, you should print out the following exact error message: error: cannot open file 'input.txt' and then exit with return code 1.
- [X]   If malloc fails print the error message `malloc failed` exit with return code 1.
- [X]   If the user runs reverse with too many arguments, print `usage: reverse <input> <output>` and exit with return code 1.
- [X]   On any error, you should print the error to the screen using *fprintf()*, and send the error message to *stderr.*
- [X]   When invoked with just one command-line argument, the user supplies the input file, but the file should be printed to the screen.
- [X]   When invoked without any arguments, your reversing program should read from standard input (stdin).
