/*
Insertion Sort-
Compares The Previous Adjacent Values and Swaps if it finds a bigger number than the selected key.
Worst Case - O(n²)
Average Case - Θ(n²)
Best Case - Ω(n)
*/

#include <stdio.h>

void insertionsort(int *arr, int size)
{
    int i, j, key;

    for (i = 1; i < size; i++)
    {
        j = i - 1;                  // Start comparing with the element before the current element.
        key = arr[i];               // Store the current element in a temporary variable.

                                    // Move elements greater than the current element to one position ahead
                                    // until the correct position for the current element is found.
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];    // Shift elements to the right.
            j--;                    // Move to the previous element to compare.
        }

        arr[j + 1] = key;           // Insert the current element in its correct position.
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

    insertionsort(a, n);        // Call the Insertion Sort function to sort the array.

    printf("Sorted array: ");
    show(a, n);                 // Display the sorted array after sorting.
}
