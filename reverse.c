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
    //int lengths = 10;
    char **lines;
    size_t buffsize = 32;
    lines = malloc(buffsize * sizeof(char*));

    /* Method for array allocation by anioss from stackoverflow.com */
    /* MAN: Alternatively, before calling getline(), *lineptr can contain a pointer to a malloc(3)-allocated buffer *n bytes in size.
    If the buffer is not large enough to hold the line, getline() resizes it with realloc(3), updating *lineptr and *n as necessary. */
    int length, index = 0;
    lines[0] = NULL;
    while ((length = getline(&lines[index], &buffsize, input)) != -1) {
        lines[index + 1] = NULL;
        index++;
    }

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
    if (argc != 3) {
        printf("usage: reverse <input> <output>\n");
        exit(1);
    }
    
    FILE *input, *output;
    {
        input = openFile(argv[1], "r");
        output = openFile(argv[2], "w");
        reverse(input, output);
        fclose(input);
        fclose(output);
    }

    return 0;
}
