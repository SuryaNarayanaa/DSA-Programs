#include "helper_functions.h"

int parent(int ind)
{
    if(ind%2==0)
    {
        return (ind/2)-1;
    }
    return ind/2;
}


int left(int ind)
{
    return 2*ind+1;
}

int right(int ind)
{
    return 2*ind+2;
}
void downheap(int arr[], int ind, int size)
{
    int l = left(ind);
    int r = right(ind);
    int min = ind;

    if(l<size && arr[l]>arr[min])
    {
        min = l;
    }
    
    if(r<size && arr[r]>arr[min])
    {
        min = r;
    }

    if(ind!=min)
    {
        swap(&arr[min],&arr[ind]);
        downheap(arr, min, size);
    }

}

void heapify(int arr[], int size)
{
    for(int i=size/2-1  ;i>=0;i--)
    {
        downheap(arr  ,i, size);
    }
}

void heapsort(int arr[], int size)
{
    heapify(arr, size);
    for (int i=size-1; i>0 ; i--)
    {
        swap(&arr[0], &arr[i]);
            downheap(arr, 0 , i);

    }
    

}


int main()
{
    int size =10;
    int arr[size];

    generateRandomArray(arr, size, 0, 32);
      
    printf("Before sorting :\n");
    printArray(arr,size);

    heapsort(arr,size);
    printf("After sorting :\n");
    printArray(arr,size);
     if (isSorted(arr, size)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }


    return 0;
}

