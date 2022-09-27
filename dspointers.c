#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    const int x=5;
    int * p = &x;
    *p=6;
    printf("x= %d\n", x);
    printf("*p= %d\n", *p);
    return 0;
}