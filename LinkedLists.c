//working with linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//we also wanna print our list
void printList(struct Node *n){
    //how do we know its not the end.. till not null 
    while (n != NULL){
        printf("%d", n->data);
        n=n->next;
    }
}


//driver code
int main(){
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;
    struct Node *fourth=NULL;
    struct Node *fifth=NULL;
    struct Node *sixth=NULL;

    //now we allocate 3 nodes in the heap
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth  = (struct Node*)malloc(sizeof(struct Node));

  /* 5 blocks have been allocated dynamically.
     We have pointers to these 5 blocks as head,
     second and third and so on 
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+

    # represents any random value.
    Data is random because we haven’t assigned
    anything yet  */

//lets say we're creating 6 3 4 2 3
    head ->data=6;     //assign data to the first node
    head ->next=second; //link first node with the second node

    second ->data=3;
    second ->next= third;

    third -> data=4;
    third-> next = fourth;

    fourth -> data=2;
    fourth -> next= fifth;

    fifth -> data=3;
    fifth -> next= NULL;

    printList(head);

    return 0;
}