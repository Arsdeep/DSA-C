#include <stdio.h>

// Linear search function to find the target element in an integer array.
// Time Complexity: O(n)
// Parameters:
// - arr: Pointer to the integer array.
// - size: The size of the array.
// - target: The element to be searched for in the array.
// Returns:
// - The index of the target element if found.
// - -1 if the target element is not found in the array.

int LinearSrch(int *arr, int size, int target)
{
    for (int i = 0; i < size; i++)      // Loop through the elements of the array.
    {
        if (arr[i] == target)           // Check if the current element is the target.
            return i;                   // Return the index of the target element.
    }
    return -1;                          // Return -1 if the target element is not found in the array.
}

void main()
{
    int arr[] = {3, 6, 8, 7, 1, 2, 5, 4, 9, 0};
    int n = sizeof(arr) / sizeof(int);      // Calculates the size of the array.

    int target = 7;                         // The element to be searched for.

    int i = LinearSrch(arr, n, target);     // Call the linear search function.

    if (i != -1)
        printf("Target %d found at index %d", target, i); // Print the target element and its index.
    else
        printf("Target not found");
}
