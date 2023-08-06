/*
Merge Sort-
First Divides the whole array into parts then
starts combining it one by one by sorting the elements into a bigger array.
Worst Case - O(n*log(n))
Average Case - Θ(n*log(n))
Best Case - Ω(n*log(n))
*/

#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays into a single sorted array.
// Parameters:
// - arr: Pointer to the integer array.
// - low: The starting index of the first subarray.
// - high: The ending index of the second subarray.
// - mid: The ending index of the first subarray and starting index of the second subarray.
// Returns:
// - The merged sorted array.
int merge(int *arr, int low, int high, int mid)
{
    int *b = (int *)malloc((high - low + 1) * sizeof(int)); // Allocate memory for the temporary array.

    int i, j, k;
    i = low;      // Index for the first subarray.
    j = mid + 1;  // Index for the second subarray.
    k = 0;        // Index for the temporary array.

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])    // Compare elements from both subarrays and copy the smaller one to the temporary array.
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    // Copy any remaining elements from the first subarray.
    while (i <= mid)
        b[k++] = arr[i++];

    // Copy any remaining elements from the second subarray.
    while (j <= high)
        b[k++] = arr[j++];

    // Copy the merged sorted elements from the temporary array back to the original array.
    for (i = low, j = 0; i <= high; i++)
        arr[i] = b[j++];

    free(b); // Free the dynamically allocated temporary array.
}

// Merge Sort function to sort an integer array in ascending order.
// Parameters:
// - arr: Pointer to the integer array to be sorted.
// - low: The starting index of the array.
// - high: The ending index of the array.
void mergesort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2; // Calculate the middle index.

        mergesort(arr, low, mid);         // Recursively sort the left subarray.
        mergesort(arr, mid + 1, high);    // Recursively sort the right subarray.
        merge(arr, low, high, mid);       // Merge the two sorted subarrays.
    }
}

// Function to display the elements of an integer array.
// Parameters:
// - a: Pointer to the integer array.
// - n: The size of the array.
void show(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\b\n");
}

void main()
{
    int a[] = {1, 5, 2, 6, 4, 7, 32, 55, 34, 56, 23, 45, 23, 9, 8};
    int n = sizeof(a) / sizeof(int);

    printf("Original array: ");
    show(a, n); // Display the original array before sorting.

    mergesort(a, 0, n - 1); // Call the Merge Sort function to sort the array.

    printf("Sorted array: ");
    show(a, n); // Display the sorted array after sorting.
}
