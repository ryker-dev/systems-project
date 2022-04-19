#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){

    char buffer[10];
    char file[256];
    int i=1;
    while (i < argc){
        strcpy(file, argv[i]);

        FILE *fp = fopen(file, "r");

        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }

        while (fgets(buffer,sizeof(buffer),fp) != NULL){
            printf("%s" ,buffer);
        }

        fclose(fp); 
        i++;
    }

    return 0;
}