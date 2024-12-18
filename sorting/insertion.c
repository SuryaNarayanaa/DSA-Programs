#include "helper_functions.h"


// Pick the current element and insert it into the sorted part of the array by shifting larger elements to the right.

  void  insertion(int arr[],int size)
  {
    int i, j , key;
    for( i=1 ; i<size ; i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 &&  arr[j]>key)
        {
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = key;
    }
  }






int main()
{
    int size =10;
    int arr[size] ;
    generateRandomArray(arr , size, 0 , 20);
    
    printf("Before sorting :\n");
    printArray(arr,size);

    insertion(arr,size);
    printf("After sorting :\n");
    printArray(arr,size);

    if (isSorted(arr, size)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    return 0;
}
