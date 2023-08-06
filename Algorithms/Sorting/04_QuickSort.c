/*
Quick Sort-
First Puts a number in its correct spot then splits the array, then sorts in it
Worst Case - O(n²)
Average Case - Θ(n*log(n))
Best Case - Ω(n*log(n))
*/

#include <stdio.h>

// Function to find the pivot element for Quick Sort.
// Parameters:
// - arr: Pointer to the integer array.
// - low: The starting index of the array.
// - high: The ending index of the array.
// Returns:
// - The pivot index after rearranging elements.
int pivot(int *arr, int low, int high)
{
    int p = low;                    // Choose the first element as the pivot.
    int temp;

    low++;                          // Increment low index to start from the next element.

    while (1)
    {
        while (arr[low] < arr[p])   // Find an element on the left side greater than the pivot.
            low++;

        while (arr[high] > arr[p])  // Find an element on the right side smaller than the pivot.
            high--;

        if (low < high)
        {
                                    // Swap the elements found on the left and right side with respect to the pivot.
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
        else
            break;
    }

                                    // Move the pivot element to its correct position in the sorted array.
    temp = arr[p];
    arr[p] = arr[high];
    arr[high] = temp;

    return high;                    // Return the pivot index.
}

// Quick Sort function to sort an integer array in ascending order.
// Parameters:
// - arr: Pointer to the integer array to be sorted.
// - low: The starting index of the array.
// - high: The ending index of the array.
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = pivot(arr, low, high);  // Find the pivot index using the pivot function.
        quicksort(arr, low, p - 1);     // Recursively sort the left subarray.
        quicksort(arr, p + 1, high);    // Recursively sort the right subarray.
    }
}

void show(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\b\n");
}

void main()
{
    int a[] = {1, 5, 2, 6, 4, 7, 3, 9, 8};
    int n = sizeof(a) / sizeof(int);

    printf("Original array: ");
    show(a, n);                 // Display the original array before sorting.

    quicksort(a, 0, n - 1);     // Call the Quick Sort function to sort the array.

    printf("Sorted array: ");
    show(a, n);                 // Display the sorted array after sorting.
}
