#include "types.h"
#include "stat.h"
#include "user.h"

// Swap two integers
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Simple bubble sort
void bubble_sort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf(1, "Usage: _mysort num1 num2 ...\n");
        exit();
    }

    int numbers[64]; // max 16 numbers for simplicity
    int n = argc - 1;
    if(n > 16) n = 16;

    // Convert command-line arguments to integers
    for(int i = 0; i < n; i++) {
        numbers[i] = atoi(argv[i+1]);
    }

    // Sort
    bubble_sort(numbers, n);

    // Print sorted numbers
    printf(1, "Sorted: ");
    for(int i = 0; i < n; i++) {
        printf(1, "%d ", numbers[i]);
    }
    printf(1, "\n");

    exit();
}

