#include "helper_functions.h"

// Algorithm
void bubble_sort(int arr[], int size)
{
    int swapped =1;
    for(int i=0;i,size ; i++)
    {   if(!swapped)break;
        swapped =0;
        for(int j = 0 ;j<size-i;j++)
        {   
            if(arr[j+1]<arr[j])
            {
                swap(&arr[j+1], &arr[j]);
                swapped = 1;
            }

        }

    }
}





int main() {
    int size = 10;
    int arr[size];

    generateRandomArray(arr, size, 1, 100);

    printf("Original array:\n");
    printArray(arr, size);

    bubble_sort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    if (isSorted(arr, size)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    return 0;
}
