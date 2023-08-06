/*
Selection Sort-
Finds the Smallest value in the array.
Then Swaps the Smallest value with the First Value, then Continues the process with the left array.
Worst Case - O(n²)
Average Case - Θ(n²)
Best Case - Ω(n²)
*/

#include <stdio.h>

void selectionsort(int *arr, int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            // Compare the current element with the rest of the elements in the array.
            // If a smaller element is found, swap it with the current element.
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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

    selectionsort(a, n);        // Call the Selection Sort function to sort the array.

    printf("Sorted array: ");
    show(a, n);                 // Display the sorted array after sorting.
}