// 1. Implementation of a Linked List: Given a set of values (assume int), create a linked list from them
// 2. Reversing a Linked List: Given a Linked List, reverse it
// 3. Chunk Reversing a Linked List for any chunk size in range 1 to n (inclusive): Given a Linked List, and an integer k representing the chunk size, chunk-reverse the list 
// 4. Selection Sort Algorithm: Given an array of values (assume int), use selection sort to sort them



#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct node {
    int val;
    struct node *next;
    //struct node * , is a pointer to an element of a structure node. It basically stores the address of any variable of type 'node' ( A custom structure ).
    // we're dealing with addresses of nodes, not the actual nodes themselves (dealing with pointers to the nodes)
};
typedef struct node *NodeAddress; //we're creating a new dataytype which we're calling nodeaddress. Nodeadress is basically the address of a node. 



void bubbleSort(int *a, int n){
    int done, i,t, swap;

    //here were not traversing through the part that isnt solved, only the unsolved part;that's what the varible done is for.

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



NodeAddress bubbleSortLinkedList(NodeAddress head){
    NodeAddress c, lastDone;
    int t;

    for(lastDone = NULL; lastDone!=head; lastDone=c){

        for(c=head; c->next!=lastDone; c=c->next){

            if (c->val > c->next->val){
                t = c->val;
                c->val= c->next->val;
                c->next->val= t;
            }
        } //this is the end of the c loop, the element has been bubbled up to position c

    }

    return head;

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



NodeAddress linkedListFromArray(int *a, int n) {

    int i;
    NodeAddress head= NULL;
    NodeAddress temp= NULL;

    // we declare some variables, i, head and temp
    //first we check if n is positive, if it's not then everythings NULL anyway
    //if it is positive, we build a "house" for head
    //then we malloc it (aallocate space/x byes of memory to it)
    //we set val = a[0]
    //and so on so forth- and then we start running the loop 
    //we haven't freed/destroyed the linked list tho so do in int main
    if(n>0){
        head= malloc(sizeof(struct node));
        head -> val= a[0];
        head -> next= NULL;
        temp = head;
    }

    for(int i=1; i<n; i++){
        temp->next= malloc(sizeof(struct node)); //we're assuming that head already exists and it belongs to temp
        temp = temp->next; // if someone gives us another value we "malloc it" "build a house for it" and store it here - and we've "entered" the house
        temp->val = a[i]; //we're setting the value here
        temp->next=NULL;
    }

    return head;

}



void freeLinkedList(NodeAddress head){
    //we cant just destroy the element because then we lost the next address
    NodeAddress prev; //prev returns an iterator pointing to the element after being advanced by certain number of positions in the reverse direction.
    while(head){
        prev=head;
        head=head->next;
        free(prev);
    }

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

void printLinkedList(NodeAddress head){
    NodeAddress c;
    printf("Linked List = " );
    for(c=head; c!=NULL; c=c->next) {
        printf( c==head?"%d":", %d", c->val);
    }
    printf(".\n");

}



int main(int argc, char **argv){
    int * a;
    int n = 10; //size of array
    //we have an empty pointer and we're saying we wanna put 10 things inside of it

    NodeAddress list;


    srand(time(NULL)); 

    a= generateArray(n); //send into it the size n
    list= linkedListFromArray(a,n);
    
    printArray(a,n);
    bubbleSort(a,n);
    printArray1(a,n);

    printf("\n");

    printLinkedList(list);
    bubbleSortLinkedList(list);
    printLinkedList(list);


    //it prints the arrays and the linked list from the old array

    free(a); //there must always be a corresponding free statement for a malloc
    freeLinkedList(list);

    return 0;
}