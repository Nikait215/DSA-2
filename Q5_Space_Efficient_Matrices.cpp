/*
    UCS301 - Data Structures
    Lab Assignment 2 - Week 2 & Week 3

    Q5. Space-Efficient Matrix Representation

    Types of matrices:
    1. Diagonal Matrix
    2. Tri-diagonal Matrix
    3. Lower Triangular Matrix
    4. Upper Triangular Matrix
    5. Symmetric Matrix
*/

#include <iostream>
using namespace std;

int main()
{
    int choice;
    int n;

    cout << "===== SPACE-EFFICIENT MATRIX REPRESENTATION =====\n";

    cout << "\n1. Diagonal Matrix";
    cout << "\n2. Tri-diagonal Matrix";
    cout << "\n3. Lower Triangular Matrix";
    cout << "\n4. Upper Triangular Matrix";
    cout << "\n5. Symmetric Matrix";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    // ------------------------------------------------
    // 1. DIAGONAL MATRIX
    // ------------------------------------------------

    if (choice == 1)
    {
        cout << "\nEnter size of diagonal matrix: ";
        cin >> n;

        if (n < 1 || n > 10)
        {
            cout << "Invalid size. Enter a value between 1 and 10.\n";
            return 0;
        }

        int diagonal[10];

        cout << "\nEnter diagonal elements:\n";

        for (int i = 0; i < n; i++)
        {
            cin >> diagonal[i];
        }

        cout << "\nDiagonal Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << diagonal[i] << " ";
                else
                    cout << "0 ";
            }

            cout << endl;
        }
    }

    // ------------------------------------------------
    // 2. TRI-DIAGONAL MATRIX
    // ------------------------------------------------

    else if (choice == 2)
    {
        cout << "\nEnter size of tri-diagonal matrix: ";
        cin >> n;

        if (n < 1 || n > 10)
        {
            cout << "Invalid size. Enter a value between 1 and 10.\n";
            return 0;
        }

        int lower[10];
        int mainDiagonal[10];
        int upper[10];

        cout << "\nEnter main diagonal elements:\n";

        for (int i = 0; i < n; i++)
        {
            cin >> mainDiagonal[i];
        }

        if (n > 1)
        {
            cout << "\nEnter lower diagonal elements:\n";

            for (int i = 0; i < n - 1; i++)
            {
                cin >> lower[i];
            }

            cout << "\nEnter upper diagonal elements:\n";

            for (int i = 0; i < n - 1; i++)
            {
                cin >> upper[i];
            }
        }

        cout << "\nTri-diagonal Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cout << mainDiagonal[i] << " ";
                }
                else if (i == j + 1)
                {
                    cout << lower[j] << " ";
                }
                else if (j == i + 1)
                {
                    cout << upper[i] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }

            cout << endl;
        }
    }

    // ------------------------------------------------
    // 3. LOWER TRIANGULAR MATRIX
    // ------------------------------------------------

    else if (choice == 3)
    {
        cout << "\nEnter size of lower triangular matrix: ";
        cin >> n;

        if (n < 1 || n > 10)
        {
            cout << "Invalid size. Enter a value between 1 and 10.\n";
            return 0;
        }

        int lower[10][10];

        cout << "\nEnter lower triangular elements:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> lower[i][j];
            }
        }

        cout << "\nLower Triangular Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                    cout << lower[i][j] << " ";
                else
                    cout << "0 ";
            }

            cout << endl;
        }
    }

    // ------------------------------------------------
    // 4. UPPER TRIANGULAR MATRIX
    // ------------------------------------------------

    else if (choice == 4)
    {
        cout << "\nEnter size of upper triangular matrix: ";
        cin >> n;

        if (n < 1 || n > 10)
        {
            cout << "Invalid size. Enter a value between 1 and 10.\n";
            return 0;
        }

        int upper[10][10];

        cout << "\nEnter upper triangular elements:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                cin >> upper[i][j];
            }
        }

        cout << "\nUpper Triangular Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= j)
                    cout << upper[i][j] << " ";
                else
                    cout << "0 ";
            }

            cout << endl;
        }
    }

    // ------------------------------------------------
    // 5. SYMMETRIC MATRIX
    // ------------------------------------------------

    else if (choice == 5)
    {
        cout << "\nEnter size of symmetric matrix: ";
        cin >> n;

        if (n < 1 || n > 10)
        {
            cout << "Invalid size. Enter a value between 1 and 10.\n";
            return 0;
        }

        int symmetric[10][10];

        cout << "\nEnter lower triangular elements including diagonal:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> symmetric[i][j];
            }
        }

        // Copy lower triangle to upper triangle
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                symmetric[j][i] = symmetric[i][j];
            }
        }

        cout << "\nSymmetric Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << symmetric[i][j] << " ";
            }

            cout << endl;
        }
    }

    else
    {
        cout << "\nInvalid choice. Please choose between 1 and 5.\n";
    }

    return 0;
}