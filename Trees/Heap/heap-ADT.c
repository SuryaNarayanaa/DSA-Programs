#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *arr;
    int capacity;
    int size;
}Heap;
void swap(int*a,int*b);
int parent(int child)
{
    return (int)(child-1)/2;
}
void initHeap(Heap* heap, int capacity)
{
    heap->arr = (int*)malloc(sizeof(int)*capacity);
    heap->capacity =capacity;
    heap->size =0;
}

void upheap(Heap* heap, int  ind)
{   if(ind<=0)return ;
    int p = parent(ind);
    if(p<heap->size && heap->arr[ind]<heap->arr[p])
    {
        swap(&heap->arr[ind],&heap->arr[p]);
    }
    upheap(heap, p);
}
void insert(Heap* heap, int data)
{
    heap->arr[heap->size++] =data;
    upheap(heap , heap->size-1);
}

void printheap(Heap* heap)
{
    for(int i=0;i<heap->size;i++)
    {
         printf("%d--",heap->arr[i]);
    }
}


int leftChild(int parent)
{
    return (int)(2*parent)+1;
}



int rightChild(int parent)
{
    return (int)(2*parent)+2;
}


void swap(int*a,int*b)
{
    int t = *a;
    *a = *b;
    *b=t;
}

void downheap(Heap* heap ,int ind)
{
    int l = leftChild(ind);
    int r = rightChild(ind);
    int min = ind;
    if(l<heap->size && heap->arr[l]<heap->arr[min])
    {
        min =l;
    }
    if(r<heap->size && heap->arr[r]<heap->arr[min])
    {
        min = r;
    }

    if(min!=ind)
    {swap(&heap->arr[min], &heap->arr[ind]);
        downheap(heap, min);}

}

int removeMin(Heap* heap)
{
    int data = heap->arr[0];                   // Store the minimum element
    heap->arr[0] = heap->arr[heap->size - 1];  // Replace root with the last element
    heap->size--;                              // Decrease the heap size
    downheap(heap, 0);                         // Restore the heap property
    return data;
}


int main() {
    Heap heap;
    initHeap(&heap, 10);

    // Insert elements
    for (int i = 10; i > 0; i--) {
        insert(&heap, i);
    }

    // Build the heap

    // Print the heap

    int initialSize = heap.size;
    for(int i = 0; i < initialSize; i++)
    {
        printf("%d -- ", removeMin(&heap));
    }
    return 0;
}
