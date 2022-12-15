//This code is to implement a stack.

#include <stdio.h>
#include <stdlib.h>
//#include "array.h"

struct stack_type {
    int top;
	int capacity;
	int* values;
};

typedef struct stack_type stack;


stack* create_stack(int capacity) {

    stack* stack_obj = (stack*) malloc(sizeof(struct stack_type));

	stack_obj -> capacity = capacity;
	stack_obj -> top = -1;
	stack_obj -> values = (int*) malloc(stack_obj -> capacity * sizeof(int));

	return stack_obj;
}


/*
what i was trying to do here

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
*/


int is_full(stack* stack_obj) {
	return (stack_obj -> top == stack_obj -> capacity - 1);
}

int is_empty(stack* stack_obj) {
	return (stack_obj -> top == -1);
}

void push(stack* stack_obj, int value) {
	if (is_full(stack_obj)) {
	}
	stack_obj -> values[++(stack_obj -> top)] = value;
}

int pop(stack* stack_obj) {
	if (is_empty(stack_obj)) {
		return -2147483648; //we have this depending on the fact that we mallocted xyz space initially etc- the capacity it can extend to and so on.
	}
	return stack_obj -> values[stack_obj -> top--];
}


/*
What we're trying to do here...

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

*/


int peek(stack* stack_obj)
{
	if (is_empty(stack_obj)) {
		return -2147483648;
	}
	return stack_obj -> values[stack_obj -> top];
}

void print_stack(stack* stack_obj) {

	for (int i = stack_obj -> top; i >= 0; i--) {
		printf("%d, ", stack_obj -> values[i]);
	}
}

int main() {
//this here is just the driver code
	int size = 5;
	int* array = create_array(size);
	print_array(array, size);

    stack* stack_obj = create_stack(size);
	for (int i = 0; i < size; i++) {
		push(stack_obj, array[i]);
	}
    print_stack(stack_obj);
	printf("\n");

    return 0;
}