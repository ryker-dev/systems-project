#include <stdio.h>
#include <stdlib.h>

/* File opening and error handling */
FILE *openFile(const char* name, char* mode) {
    FILE *fp = fopen(name, "r");

    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", name);
        exit(1);
    }

    return fp;
}

void reverse(FILE *input, FILE *output) {
    /* Code here */
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
