#include <stdio.h>

#define SIZE 9

int arr[SIZE] = {5, 9, 3, 68, 46, 97, 31, -76, -85};

void merge_sort(int low, int high);
void merge(int low, int mid, int high);

int main() {
    int i;
    merge_sort(0, SIZE - 1);
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void merge(int low, int mid, int high) {
    int temp[SIZE];
    int i = low, k = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
