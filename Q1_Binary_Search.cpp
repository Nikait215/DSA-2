/*
    UCS301 - Data Structures
    Lab Assignment 2 - Week 2 & Week 3

    Q1. Binary Search

    This program demonstrates:
    1. Linear Search
    2. Binary Search

    Binary Search is faster than Linear Search for a sorted array.
    Time Complexity:
        Linear Search  -> O(n)
        Binary Search  -> O(log n)
*/

#include <iostream>
using namespace std;

// Linear Search Function
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// Binary Search Function
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            // Search in the right half
            low = mid + 1;
        }
        else
        {
            // Search in the left half
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[100];
    int n, key;

    cout << "===== LINEAR SEARCH AND BINARY SEARCH =====\n";

    cout << "\nEnter number of elements (1 to 100): ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid size. Please enter a value between 1 and 100.\n";
        return 0;
    }

    cout << "Enter " << n << " elements in sorted order:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nEnter element to search: ";
    cin >> key;

    // Linear Search
    int linearResult = linearSearch(arr, n, key);

    if (linearResult != -1)
    {
        cout << "\nLinear Search: Element found at position "
             << linearResult + 1 << ".\n";
    }
    else
    {
        cout << "\nLinear Search: Element not found.\n";
    }

    // Binary Search
    int binaryResult = binarySearch(arr, n, key);

    if (binaryResult != -1)
    {
        cout << "Binary Search: Element found at position "
             << binaryResult + 1 << ".\n";
    }
    else
    {
        cout << "Binary Search: Element not found.\n";
    }

    cout << "\nTime Complexity:\n";
    cout << "Linear Search  : O(n)\n";
    cout << "Binary Search  : O(log n)\n";

    return 0;
}