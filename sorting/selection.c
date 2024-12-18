#include "helper_functions.h"


int compare(int min , int a)
{
    if(a < min)
    {return 0;}
    else{return 1;}
}
// Algorithm


// find the min from the unsoretd part and swap it with the first element of the unsorted part
void selection(int arr[],int size)
{
    int i, j, min;
    for( i=0 ;i<size ; i++)
    {   min = i;
        for(j=i+1; j<size; j++)
        {
            if(!compare(arr[min], arr[j]))
            {
                min = j;
            }
        }
        if(min!= i)
        {swap(&arr[min],&arr[i]);}
    }

}
int main()
{
    int size= 10;
    int arr[size];

    generateRandomArray(arr, size , 0, 11);
    printf("Before sorting :\n");
    printArray(arr,size);

    selection(arr,size);
    printf("After sorting :\n");
    printArray(arr,size);

    if (isSorted(arr, size)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    return 0;
}
