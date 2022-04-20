#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){

    char line[256];
    //char *line2 = NULL;
    //size_t len = 0;

    if (argc == 1){
        printf("my-grep: searchterm [file ...]\n");
        exit(1); 
    }/*
    else if (argc == 2){
        printf("2 argc\n");
        //while ((read = getline(&line, &len, stream)) != -1) {
        while (getline(&line2, &len, stdin) != NULL) {
            printf("Retrieved line of length %zu :\n", read);
            printf("%s", line);
        }

    }*/
    else{

        //int last_arg = argc; // poois?

        //printf("arg määrä = %d\n",last_arg);
        //char filename[]="test.txt",line[200],search_string[]="foo";
        //char filename[256];
        //char search_string[256];
        //printf("%d\n",argc);
        
        for (int i = 2; i < argc; i++){

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-grep: cannot open file\n");
                exit(1);
            }

            //char line[256];
            /*
            fp=fopen(filename,"r");
            if(!fp){
                perror("could not find the file");
                exit(0);
            }
            */
           
            while ( fgets ( line, 256, fp ) != NULL ){ // getline?
                //if(strstr(line,search_string))
                if(strstr(line,argv[1]))
                fputs ( line, stdout ); 
            }

            fclose(fp);
        }
    }
    return 0;
}