#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define BUFFERLEN 255

//char BUFFER[BUFFERLEN];

FILE *openFile(char name[20], char mode[20]) {
    FILE *fp = fopen(name, mode);

    if (fp == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    return fp;
}

/*
char* RLE() {

} */

/* setmode(fileno(stdout), O_BINARY) */

int main(int argc, char const *argv[])
{
    FILE *in = openFile("test.txt", "r");
    //FILE *out = openFile("output.txt", "w");
    char c, curChar;
    char *buff[5];
    int counter = 0;
    while ((c = getc(in)) != EOF) {
        if (counter < 1 || c != curChar) {
            if (counter > 0 ) {
                fwrite(counter, 1, sizeof(c), stdout);
            }
            counter = 0;
            curChar = c;
        } else {
            counter++;
        }
    };
    return 0;
}
