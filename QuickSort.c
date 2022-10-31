// quick sort algorithm in c

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