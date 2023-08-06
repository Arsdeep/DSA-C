#include <stdio.h>

// Binary search function for sorted arrays.
// Time Complexity: O(log(n))
// Parameters:
// - arr: Pointer to the sorted integer array.
// - high: Index of the last element in the array (size of the array - 1).
// - target: The element to be searched for in the array.
// Returns:
// - The index of the target element if found.
// - -1 if the target element is not found in the array.

int BinarySrch(int *arr, int high, int target)
{
    int low = 0, mid;
    high--;                             // Adjust high to index of the last element.

    while (low <= high)
    {
        mid = (high + low) / 2;         // Calculate the middle index.

        if (arr[mid] == target)         // Check if the middle element is the target.
            return mid;                 // Return the index of the target element.
        else
        {
            if (arr[mid] < target)      // If middle element is less than target, search in the right half.
            {
                low = mid + 1;          // Update the low index to the next element.
            }
            else                        // If middle element is greater than target, search in the left half.
            {
                high = mid - 1;         // Update the high index to the previous element.
            }
        }
    }
    return -1;                          // Return -1 if the target element is not found in the array.
}

void main()
{
    int arr[] = {1, 4, 6, 12, 23, 45, 67, 78, 96};
    int n = sizeof(arr) / sizeof(int);                      // Calculates the size of the array.

    int target = 96;                                        // The element to be searched for.

    int i = BinarySrch(arr, n, target);                     // Call the binary search function.

    if (i != -1)
        printf("Target %d found at index %d", target, i);   // Print the target element and its index.
    else
        printf("Target not found");
}
