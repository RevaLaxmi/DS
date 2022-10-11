// 1. Implementation of a Linked List: Given a set of values (assume int), create a linked list from them
// 2. Reversing a Linked List: Given a Linked List, reverse it
// 3. Chunk Reversing a Linked List for any chunk size in range 1 to n (inclusive): Given a Linked List, and an integer k representing the chunk size, chunk-reverse the list 
// 4. Selection Sort Algorithm: Given an array of values (assume int), use selection sort to sort them

#include <stdio.h>
#include <stdlib.h>

int * generateArray(int n){
    int * t = malloc( n * sizeof(int)); //we're declaring a new address
    if(t) {
        for(int i=0; i<n; i++) {t[i] = i;}
    }
    return t;
    //this just generates the space for an array
}

void printArray(int *a, int n){
    printf("Array = " );
    for(int i=0; i<n; i++) {
        printf( i?", %d":"%d", a[i]);
    }
    printf(".\n");
}


void printArray1(int *a, int n){
    for(int i=0; i<n; i++) {
        printf(" %d ", a[i]);
    }
}

int main(int argc, char **argv){
    int * a;
    int n = 10; //size of array
    //we have an empty pointer and we're saying we wanna put 10 things inside of it

    a= generateArray(n); //send into it the size n
    printArray(a,n);

    free(a); //there must always be a corresponding free statement for a malloc
    return 0;
}