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

    char newChar, curChar;
    int buff[1];
    int counter = 0b0000000;
    while ((newChar = getc(in)) != EOF) {
        if (counter > 0) {
            printf("counter > 0\n");
            if (newChar != curChar) {
                buff[0] = counter;
                printf("%d%c|", buff[0], curChar);
                fwrite(buff, 4, 1, stdout);
                fputc(curChar, stdout);
                curChar = newChar;
                counter = 0b00000000;
                continue;
            }
            counter++;
        } else {
            printf("increase\n");
            counter++;
            curChar = newChar;
        }
    };

    return 0;
}
