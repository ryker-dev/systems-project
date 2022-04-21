/* Author: ryker-dev */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 10

/* File opening and error handling */
FILE *openFile(const char* name, char* mode) {
    FILE *fp = fopen(name, mode);

    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", name);
        exit(1);
    }

    return fp;
}

void reverse(FILE *input) {
    /* TODO: add malloc errors */
    //int lengths = 10;
    long *linestarts;
    int buffsize = BUFFERSIZE;
    linestarts = malloc(buffsize * sizeof(long*));

    /*  Method for array allocation by anioss from stackoverflow.com
        "getline line by line and then store entire lines in an array in C [closed]"
        https://stackoverflow.com/questions/34296079/getline-line-by-line-and-then-store-entire-lines-in-an-array-in-c
    */
    /*  MAN: Alternatively, before calling getline(), *lineptr can contain a pointer to a malloc(3)-allocated buffer *n bytes in size.
        If the buffer is not large enough to hold the line, getline() resizes it with realloc(3), updating *lineptr and *n as necessary.
    */

   char c;
   long counter = 0;
   int index = 0;
   while ((c = getc(input)) != EOF) {
       if (c == '\n') {
           printf("FOUND: %ld\n", counter);
           if (index + 1 == buffsize) {
               printf("BUFFER TOO SMALL!\n");
               buffsize = buffsize + BUFFERSIZE;  
               linestarts = realloc(linestarts, buffsize);
           }
           linestarts[index] = counter;
           index++;
       }
       counter++;
   }

/*     for (int i = index; i >= 0; i--) {
       fprintf(stdout, "%d\n", linestarts[i]);
    } */
}

int main(int argc, char const *argv[])
{
    /* Usage print when lacking parameters */
    if (argc < 2 || argc > 3) {
        printf("usage: reverse <input> <stdout>\n");
        exit(1);
    }
    
    FILE *input, *stdout;
    {
        input = openFile(argv[1], "r");
        /* TODO: Add file openining error */
        reverse(input);
        fclose(input);
        /* TODO: Add output to file if argc == 3 */
    }

    return 0;
}
