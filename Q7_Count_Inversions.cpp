#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    int inversions = 0;

    cout << "===== COUNT INVERSIONS =====\n";

    cout << "\nEnter number of elements (1 to 100): ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid size. Please enter a value between 1 and 100.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Count inversions
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inversions++;
            }
        }
    }

    cout << "\nNumber of inversions = " << inversions << endl;

    return 0;
}