#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    int distinctCount = 0;

    cout << "===== COUNT DISTINCT ELEMENTS =====\n";

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

    // Count distinct elements
    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate)
        {
            distinctCount++;
        }
    }

    cout << "\nNumber of distinct elements = "
         << distinctCount << endl;

    return 0;
}