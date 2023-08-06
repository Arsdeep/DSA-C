/*
Bubble Sort-

Compares Next Adjacent Values and Swaps if the Next value is Larger.
The outer loop runs (size - 1) times as the largest element will "bubble up" to the last position
after each iteration. Hence, the last element will be in its sorted position after the first pass,
and so on.

Worst Case - O(n²)
Average Case - Θ(n²)
Best Case - Ω(n)
*/

#include <stdio.h>

void bubblesort(int *arr, int size)
{
    int i, temp;
    while (--size)
    {
        for (i = 0; i < size; i++)
        {
            // Compare adjacent elements and swap them if they are in the wrong order.
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
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

    bubblesort(a, n);           // Call the Bubble Sort function to sort the array.

    printf("Sorted array: ");
    show(a, n);                 // Display the sorted array after sorting.
}
