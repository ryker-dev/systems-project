# systems-project
A project for a university course

## my-zip
```
Usage: my-zip: file1 [file2 ...]

./my-zip file1.txt file2.txt > file.z
```
- [X]   Outputs to stdout
- [X]   Outputs 5 byte chunks consisting of 4 bytes of integer binary and 1 character
- [X]   Works with an multiple argument files
- [X]   Prints usage and exits with 1 when no arguments are given

## my-unzip
```
Usage: my-unzip: file1 [file2 ...]

./my-unzip file.z > output.txt
```
- [X]   Outputs to stdout
- [X]   Reads the format from my-zip
- [X]   Works with an multiple argument files
- [X]   Prints usage and exits with 1 when no arguments are given
