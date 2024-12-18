#include "helper_functions.h"

int partition(int arr[], int low , int high)
{
    int pivot = arr[low];

    int start = low, end = high;
while(start<end)
{
    while(arr[start]<= pivot)
    {
        start++;
    }
    while(arr[end]>pivot)
    {
        end--;
    }
    if(start<end)
    {
        swap(&arr[start], &arr[end]);
    }
}

swap(&arr[low], &arr[end]);
return end;
    
}
void quicksort(int arr[], int low , int high)
{   
    if(low<high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1 , high);
    }
}

int main()
{
    int size =10;
    int arr[size];

    generateRandomArray(arr, size, 0, 32);
      
    printf("Before sorting :\n");
    printArray(arr,size);

    quicksort(arr,0,size-1);
    printf("After sorting :\n");
    printArray(arr,size);

    if (isSorted(arr, size)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    return 0;
}

