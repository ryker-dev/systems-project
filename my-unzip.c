#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define BUFFERLEN 5

char BUFFER[BUFFERLEN];

FILE *openFile(const char* name) {
    FILE *fp = fopen("output.z", "rb");

    if (fp == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    return fp;
}

void decode(FILE *fp) {
    int num = 0;
    char c;
    while (fread(&num,4,1,fp) == 1) {
        fread(&c,1,1,fp);
        for (int i = 0; i < num; i++)
        {
            printf("%c", c);
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *fp;
    
    for (int i = 1; i < argc; i++)
    {
        fp = openFile(argv[i]);
        decode(fp);
    }

    return 0;
}
