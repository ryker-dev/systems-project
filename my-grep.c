#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){

    FILE *fp;
    int last_arg = argc;
    printf("arg määrä = %d\n",last_arg);
    //char filename[]="test.txt",line[200],search_string[]="Foo";
    char filename[]="test.txt";
    char search_string[]="foo";
    char line[200];
    fp=fopen(filename,"r");
    if(!fp){
        perror("could not find the file");
        exit(0);
    }
    while ( fgets ( line, 200, fp ) != NULL ){ /* read a line */
        if(strstr(line,search_string))
        fputs ( line, stdout ); /* write the line */
    }
    fclose ( fp );
    return 0;
}