// Implement Quick Sort with Arrays 

/*
Lets say we're working with 7 2 1 6 8 5 3 4
picks an element as a pivot and partitions the other elements around said pivot
in this case the pivot is the 4
We can think of it as making greater than and lesser than piles around the pivot. 
lesser < 4 > greater 
note: what we will proceed to do is swap positions 
7 2 1 6 8 5 3 4
|                A pointer is fixed at the pivot element. The pivot element is compared with the elements beginning from the first index.
compare 7 w 4
compare 2 w 4, now 2<4
so 2 and 7 are swapped
2 7 1 6 8 5 3 4 
  |              A pointer is fixed on 7 now
comparing 1 and 4 we get 1<4
2 1 7 6 8 5 3 4 
    |            The pointer gets incremented again 
6!<4, so we check for 8,5.. finally we get 3<4
2 1 3 6 8 5 7 4
      |          The pointer is now set on 6
and finally what we will do is check 4<=4 (so keep a lesser than equal to operand)
2 1 3 4 8 5 7 6
      |
on the LHS of 4 we have <4 and on the RHS of 4 we have >4

This entire process is repeated within the subarrays (not incld 4)
*/

#include <stdio.h>

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
    int a[]={10,11,23,44,8,15,3,9,12,45,56,45,45};
    int length=13;

    quicksort(a,length);

    // print out the array to ensure it has been sorted
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}

void quicksort(int array[], int length)
{
    quicksort_recursion(array, 0, length-1);
}


void quicksort_recursion(int array[], int low, int high)
{
    if (low<high)
    {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index-1);
        quicksort_recursion(array, pivot_index+1, high);
    }
}


int partition(int array[], int low, int high)
{
    // we're going with the assumption that the pivot value is always going to be the last value of the array
    // 6 3 7 5 1 2 4
    int pivot_value= array[high];
    
    //counter
    int i=low;

    for (int j = low; j <high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++ ; 
        }
    }

    swap(&array[i], &array[high]);

    return i;
}