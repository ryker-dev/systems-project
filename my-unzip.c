#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define BUFFERLEN 5

char BUFFER[BUFFERLEN];

FILE *openFile() {
    FILE *fp = fopen("output.z", "rb");

    if (fp == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    return fp;
}

int main(int argc, char const *argv[])
{
     FILE *in = openFile();

    int num = 0;
    char c;
    while (fread(&num,4,1,in) == 1) {
        fread(&c,1,1,in);
        for (int i = 0; i < num; i++)
        {
            printf("%c", c);
        }
    }
    
/*     fread(BUFFER,5,1,in);
    printf("%s", BUFFER); */

    return 0;
}
