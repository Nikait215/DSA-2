#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter " << n - 1 << " sorted elements from 1 to " << n << ":\n";

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    // -----------------------------------------
    // (a) LINEAR TIME METHOD
    // -----------------------------------------

    int missingLinear = n * (n + 1) / 2;

    for (int i = 0; i < n - 1; i++)
    {
        missingLinear -= arr[i];
    }

    cout << "\nMissing number using Linear Search: "
         << missingLinear << endl;

    // -----------------------------------------
    // (b) BINARY SEARCH METHOD
    // -----------------------------------------

    int low = 0;
    int high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    int missingBinary = low + 1;

    cout << "Missing number using Binary Search: "
         << missingBinary << endl;

    return 0;
}