/* Author: Juho Spoof */

/* help from https://dev-notes.eu/2019/07/Get-a-line-from-stdin-in-C/ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){

    char *line = NULL;
    size_t len = 0;

    // printing error if no arguments are given
    if (argc == 1){
        printf("my-grep: searchterm [file ...]\n");
        exit(1); 
    }
    // searching from user input if only search parameter is given as argument
    else if (argc == 2){
        if (getline(&line, &len, stdin) != -1) {
            if(strstr(line,argv[1]))
            fputs(line, stdout); 
        }
    }
    // searching one or multiple given files for search string and printing found lines
    else{
        for (int i = 2; i < argc; i++){
            
            //file opening and error handling
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-grep: cannot open file\n");
                exit(1);
            }

            //printing lines from file that match search
            while (getline(&line, &len, fp) != -1) {
                if(strstr(line,argv[1]))
                fputs(line, stdout); 
            }
            fclose(fp);
        }
        free(line); // getline() allocates memory so it has to be freed
    }

    return 0;
}