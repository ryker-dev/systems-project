#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

    printf("--alku testi--\n");   //test 1

    int size = 10;
    //int size;
    char line[10];
    FILE *fp = fopen("main.c", "r");

    if (fp == NULL) {
        printf("cannot open file\n");
        exit(1);
    }

    while (fgets(line,size,fp) != NULL){
        //char rivi = line;
        //printf("%s" ,rivi);
        printf("%s" ,line);

    }

    fclose(fp);
    printf("\n--loppu testi--\n");  //test 2
    return 0;
}