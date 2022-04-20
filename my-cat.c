#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){

    char buffer[11];
    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }

        while (fgets(buffer,sizeof(buffer) - 1,fp) != NULL){
            printf("%s" ,buffer);
        }

        fclose(fp); 
    }

    return 0;
}