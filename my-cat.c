/* Author: JuhoSpoof  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 33

int main(int argc, char const *argv[]){

    char buffer[BUFFERSIZE];
    // going through every argument
    for (int i = 1; i < argc; i++)
    {
        // file opening and error handling
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }

        //printing lines from file
        while (fgets(buffer,BUFFERSIZE - 1,fp) != NULL){
            printf("%s" ,buffer);
        }

        fclose(fp); 
    }

    return 0;
}