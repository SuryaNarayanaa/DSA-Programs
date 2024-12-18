#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if the array is sorted
int isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

// Function to generate a random array of integers
void generateRandomArray(int arr[], int size, int min, int max) {
    srand(time(0));  // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1); // Random number between min and max
    }
}

#endif
