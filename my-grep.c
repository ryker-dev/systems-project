/* help from https://dev-notes.eu/2019/07/Get-a-line-from-stdin-in-C/ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){

    char *line = NULL;
    size_t len = 0;

    if (argc == 1){
        printf("my-grep: searchterm [file ...]\n");
        exit(1); 
    }
    else if (argc == 2){
        while (getline(&line, &len, stdin) != -1) {
            if(strstr(line,argv[1]))
            fputs(line, stdout); 
        }
    }
    else{
        for (int i = 2; i < argc; i++){

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-grep: cannot open file\n");
                exit(1);
            }

            while (getline(&line, &len, fp) != -1) {
                if(strstr(line,argv[1]))
                fputs(line, stdout); 
            }
            free(line);
            fclose(fp);
        }
    }

    return 0;
}