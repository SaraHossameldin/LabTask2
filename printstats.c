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

// Approximate sqrt using iterative method
double sqrt(double x) {
    double guess = x / 2;
    if (x == 0) return 0;
    for(int i = 0; i < 20; i++) {
        guess = (guess + x/guess) / 2;
    }
    return guess;
}

// Compute mean
double mean(int arr[], int n) {
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

// Compute standard deviation
double stddev(int arr[], int n, double avg) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        double diff = arr[i] - avg;
        sum += diff * diff;
    }
    return sqrt(sum / n);
}

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf(1, "Usage: printstats num1 num2 ...\n");
        exit();
    }

    int n = argc - 1;
    int arr[n];
    int min = 0, max = 0;
    for(int i = 0; i < n; i++){
        arr[i] = atoi(argv[i+1]);
        if(i == 0) { min = max = arr[i]; }
        else {
            if(arr[i] < min) min = arr[i];
            if(arr[i] > max) max = arr[i];
        }
    }

    bubble_sort(arr, n);

    double avg = mean(arr, n);
    double sd = stddev(arr, n, avg);

    // Median
    double median;
    if(n % 2 == 1)
        median = arr[n/2];
    else
        median = (arr[n/2 - 1] + arr[n/2]) / 2.0;

    printf(1, "Count: %d\n", n);
    printf(1, "Min: %d\n", min);
    printf(1, "Max: %d\n", max);
    printf(1, "Average: %d\n", (int)avg);
    printf(1, "Median: %d\n", (int)median);
    printf(1, "Std Dev: %d\n", (int)sd);

    exit();
}



