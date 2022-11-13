// Implement Selection Sort with Array

#include <stdio.h>
  
void selection(int arr[], int n)  
{  
    // variables in use
    int i, j, small;
      
    // One by one move boundary of unsorted subarray    
    for (i = 0; i < n-1; i++)    
    {  
        //minimum element in unsorted array  
        small = i; 
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
        // Searches for the smallest element throughout the array
        // Puts that element in the first index position
            small = j;  

    // Swap the minimum element with the first element  
    //Looks for smallest elemts, waps and places. traverses again for the second smallest element, swaps (if required) and places.. and so on
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    }  
}  
  
// function to print the array  
void printArr(int a[], int n)
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
// Driver function (calling everything else)  
int main()  
{  
    int a[] = { 12, 31, 25, 8, 32, 17 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    selection(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}   