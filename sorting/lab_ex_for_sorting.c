#include <stdio.h>

void merge(int *a, int low, int mid, int high);
void selectionSort(int *a, int n);
void bubbleSort(int *a, int n);
void insertionSort(int *a, int n);
void nextGreater(int *a, int n);
int findPeak(int *a, int n);



void selectionSort(int *a, int n) {
                int in =0, out= 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;out++;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
                in++;
            }
        }
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
    printf("%INNER LOOP COMPARISONS : %d\nOUTER LOOP COMPARISONS : %d\n", in, out);}
void bubbleSort(int *a, int n) {

     int in =0, out= 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        out++;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                in++;
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

      printf("%INNER LOOP COMPARISONS : %d\nOUTER LOOP COMPARISONS : %d\n", in, out);
}
void insertionSort(int *a, int n) {
     int in =0, out= 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        out++;
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;in++;
        }
        a[j + 1] = key;
    }
  printf("%INNER LOOP COMPARISONS : %d\nOUTER LOOP COMPARISONS : %d\n", in, out);
}
void nextGreater(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int nxt_g = -1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                nxt_g = a[j];
                break;
            }
        }
        printf("%d ", nxt_g);
    }
    printf("\n");
}

int binarySearch(int *a, int n, int key) {
    int low = 0, high = n - 1;
    int num = 0;
    while (low <= high) {
            num++;
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {

            printf("Number of Iterations : %d\n", num);
            return mid;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
                printf("Number of Iterations : %d\n", num);

    return -1;
}

int linearSearch(int *a, int n, int key) {
    int num =0 ;
    for (int i = 0; i < n; i++) {


        num++;
        if (a[i] == key) {
                        printf("Number of Iterations : %d\n", num);

            return i;
        }
    }
                printf("Number of Iterations : %d\n", num);

    return -1;
}

int findPeak(int *a, int n) {
    int low = 0, high = n - 1, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (a[mid] > a[mid + 1]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    int choice;
    int a[100];
    int n;
    while (1) {
        printf("\nMenu:\n");
                printf("0. Exit\n");

        printf("1. Sort Array using Selection Sort\n");
        printf("2. Sort Array using Bubble Sort\n");
        printf("3. Sort Array using Insertion Sort\n");
        printf("5. Find Next Greater Elements\n");
        printf("6. Find Peak Element\n");
        printf("7 Linear search. \n");
                printf("8 Binary search. \n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
             case 0:
                printf("Exiting the program.\n");
                return 0;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                if (choice == 1) {
                    selectionSort(a, n);
                    printf("Sorted array \n(Selection Sort): ");
                } else if (choice == 2) {
                    bubbleSort(a, n);
                    printf("Sorted array \n(Bubble Sort): ");
                } else if (choice == 3) {
                    insertionSort(a, n);
                    printf("Sorted array \n(Insertion Sort): ");
                }

                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            case 5:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                printf("Next greater elements: ");
                nextGreater(a, n);
                break;
            case 6:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                int peakIndex = findPeak(a, n);
                printf("Peak element: %d\n", a[peakIndex]);
                break;


            case 7:

                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }


                int key ;
                printf("Enter the element to be searched : ");
                scanf("%d", &key);

                int tarind = linearSearch(a, n, key);
                printf("Target index: %d\n", tarind);
                break;

            case 8:
                    printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }


                int keys ;
                printf("Enter the element to be searched : ");
                scanf("%d", &keys);

                int tarinds = binarySearch(a, n, keys);
                printf("Target index: %d\n", tarinds);
                break;






            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
