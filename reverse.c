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
    char *buffer;
    char **lines;
    size_t buffsize = 32;
    lines = malloc(buffsize * sizeof(char*));

/*      if ((lines = (char *)malloc(1 * sizeof(int))) == NULL) {
        fprintf(stderr, "malloc failed");
        exit(1);
    } */

    int length, index = 0;
    lines[0] = NULL;
    /* Method for allocation by anioss from stackoverflow.com */
    while ((length = getline(&lines[index], &buffsize, input)) != -1) {
/*         if (lines[length - 1] == '\n') {
            lines[length - 1] = '\0';
        }; */
        printf("%s", lines[index]);
        lines[index + 1] = NULL;
        index++;
/*         lines[index] = malloc(strlen(buffer) + 1);
        strcpy(lines[index], buffer);
        index++; */
    }
    
    for (int i = index; i > -1; i--)
    {
/*         char *lastChar = lines[i][strlen(string)-1];
        if (lastChar == '\n') {} */
        printf("%s\n", lines[i]);
    }

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
