#include "helper_functions.h"



// Recursively divide the array into two halves, sort each half, and merge them into a single sorted array.


void merge(int arr[], int l , int m , int  r)
{
    int n1  = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0 ;i<n1;i++)
    {
        L[i] = arr[l+i];
    }
    for(int i=0 ;i<n2;i++)
    {
        R[i] = arr[m+i+1];
    }


    int i=0,j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while(i<n1)
    {
        arr[k++] = L[i++];
    }
    while(j<n2)
    {
        arr[k++] = L[j++];
    }

}

void mergesort(int arr[], int left ,int right)
{   if(left<right)
    {
    int mid = left+(right-left)/2;
    mergesort(arr, left,mid);
    mergesort(arr, mid+1, right);
    merge(arr , left, mid , right);
    }
}
int main()
{
    int size =10;
    int arr[size];

    generateRandomArray(arr, size, 0, 32);
      
    printf("Before sorting :\n");
    printArray(arr,size);

    mergesort(arr,0,size-1);
    printf("After sorting :\n");
    printArray(arr,size);

    if (isSorted(arr, size)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    return 0;
}

