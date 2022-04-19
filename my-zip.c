#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define BUFFERLEN 255

//char BUFFER[BUFFERLEN];

FILE *openFile() {
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    return fp;
}

int main(int argc, char const *argv[])
{
     FILE *in = openFile();

    char newChar, lastChar;
    // int buff[1];
    int counter = 0;
    while (lastChar != EOF) {
        newChar = getc(in);
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

    return 0;
}
