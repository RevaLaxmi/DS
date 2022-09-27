#include <stdio.h>
#include <stdlib.h>

int main(){
    const int var=10;
    int *ptr = &var; //this changes the address contained by the pointer 
    *ptr =12;

    printf("var = %d\n", var);
    printf("*ptr = %d\n", *ptr);

    return 0;
}
// how the address of var may or may not have changed. 
