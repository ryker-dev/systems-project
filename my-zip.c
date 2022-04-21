/* Author: ryker-dev */

#include <stdio.h>
#include <stdlib.h>

/* File opening and error handling */
FILE *openFile(const char* name) {
    FILE *fp = fopen(name, "r");

    if (fp == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    return fp;
}

/* Encodes the given file into 5 byte chunks and passes it to stdout */
void encode(FILE *fp) {
    char newChar, lastChar = 0;
    int counter = 0;
    while (lastChar != EOF) {
        newChar = getc(fp);
        if (counter > 0) {
            if (newChar != lastChar) {
                fwrite(&counter, sizeof(counter), 1, stdout);
                fputc(lastChar, stdout);
                lastChar = newChar;
                counter = 1;
            } else {
                counter++;
            }
        } else {
            counter++;
            lastChar = newChar;
        }
    };
}

int main(int argc, char const *argv[])
{
    /* Usage print when lacking parameters */
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }
    
    FILE *fp;
    for (int i = 1; i < argc; i++)
    {
        fp = openFile(argv[i]);
        encode(fp);
        fclose(fp);
    }

    return 0;
}
