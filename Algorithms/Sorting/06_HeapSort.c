/*
Merge Sort-
First Divides the whole array into parts then
starts combining it one by one by sorting the elements into a bigger array.
Worst Case - O(n*log(n))
Average Case - Θ(n*log(n))
Best Case - Ω(n*log(n))
*/

#include <stdio.h>

// Function to maintain the heap property by recursively adjusting the elements.
// Parameters:
// - arr: Pointer to the integer array representing the heap.
// - n: The size of the heap.
// - i: Index of the current node to be adjusted.
void heapify(int *arr, int n, int i)
{
    int largest = i;           // Assume the current node as the largest.
    int left = 2 * i + 1;      // Index of the left child in the heap.
    int right = 2 * i + 2;     // Index of the right child in the heap.

    // If the left child is larger than the current largest, update the largest.
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the current largest, update the largest.
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the current node, swap the current node with the largest element.
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively adjust the subtree with the new root.
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort on an integer array.
// Parameters:
// - arr: Pointer to the integer array to be sorted.
// - n: The size of the array.
void heapSort(int arr[], int n)
{
    // Build the initial max heap.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one and maintain the heap property.
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify to adjust the reduced heap.
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
