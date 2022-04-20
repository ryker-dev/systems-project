#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){

    char testvar[256];
    strcpy(testvar, argv[1]);

    printf("%s\n",testvar);
    return 0;
}
