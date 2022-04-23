/* Authors: ryker-dev, JuhoSpoof */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* File opening and error handling */
FILE *openFile(const char* name, char* mode) {
    FILE *fp = fopen(name, mode);

    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", name);
        exit(1);
    }

    return fp;
}

void reverse(FILE *input, FILE *output) {
    char **lines;
    size_t buffsize = 32;

    /* If no input was given */
    if (input == stdin) {
        char *line;
        size_t len = 0;
        if (getline(&line, &len, stdin) != -1) {
            fputs(line, stdout);
            /* Function will not continue from this point */
        }
    }

    if ((lines = malloc(buffsize * sizeof(char*))) == NULL){
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    /*  Method for array allocation by anioss from stackoverflow.com
        "getline line by line and then store entire lines in an array in C [closed]"
        https://stackoverflow.com/questions/34296079/getline-line-by-line-and-then-store-entire-lines-in-an-array-in-c
    */
    /*  MAN: Alternatively, before calling getline(), *lineptr can contain a pointer to a malloc(3)-allocated buffer *n bytes in size.
        If the buffer is not large enough to hold the line, getline() resizes it with realloc(3), updating *lineptr and *n as necessary.
    */

   /* Read lines */
    int length, index = 0;
    lines[0] = NULL;
    while ((length = getline(&lines[index], &buffsize, input)) != -1) {
        lines[index + 1] = NULL;
        index++;
    }

    /* Write lines */
    for (int i = index - 1; i > -1; i--)
    {
        fprintf(output, "%s", lines[i]);

        /* Take into account the possibility of a missing new line */
        if (lines[i][strlen(lines[i])-1] != '\n') {
            fprintf(output, "\n");
        }
    }

    free(lines);
}

int main(int argc, char const *argv[])
{
    /* Usage print when lacking parameters */
    if (argc < 1 || argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    
    /* Check for arguments */
    FILE *input, *output;
    {
        if (argc > 1) {
            input = openFile(argv[1], "r");
        } else {
            input = stdin;
        }

        if (argc == 3){
            if (!strcmp(argv[1], argv[2])){
                fprintf(stderr, "Input and output file must differ\n");
                exit(1);
            }
            output = openFile(argv[2], "w");
            
        } else {
            output = stdout;
        }

        reverse(input,output);

        fclose(input);
        if (argc == 3){
            fclose(output);
        }

    }

    return 0;
}
