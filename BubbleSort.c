// 1. Implementation of a Linked List: Given a set of values (assume int), create a linked list from them
// 2. Reversing a Linked List: Given a Linked List, reverse it
// 3. Chunk Reversing a Linked List for any chunk size in range 1 to n (inclusive): Given a Linked List, and an integer k representing the chunk size, chunk-reverse the list 
// 4. Selection Sort Algorithm: Given an array of values (assume int), use selection sort to sort them



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int *a, int n){
    int done, i,t, swap;

    for(done=0; done<n; done++){

        swap=0;
        for(i=0;i<n-1-done;i++){

            if(a[i]>a[i+1]){
                //swap these elements since they are in the wrong order
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
                swap=1;
            }
        } //end of the i loop
        if(swap==0)
        break;

    } // end of the done loop
}


int * generateArray(int n){
    int * t = malloc( n * sizeof(int)); //we're declaring a new address
    if(t) {
        for(int i=0; i<n; i++) {t[i] = rand()%1000;}
        //by doing rand()%1000 all the outputs will be b/w 0 and 999
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

    srand(time(NULL)); 

    a= generateArray(n); //send into it the size n
    printArray(a,n);
    bubbleSort(a,n);
    printArray1(a,n);

    free(a); //there must always be a corresponding free statement for a malloc
    return 0;
}