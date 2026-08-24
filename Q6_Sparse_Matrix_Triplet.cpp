/*
    UCS301 - Data Structures
    Lab Assignment 2 - Week 2 & Week 3

    Q6. Sparse Matrix using Triplet Representation

    Operations:
    1. Transpose
    2. Addition
    3. Multiplication
*/

#include <iostream>
using namespace std;

const int MAX = 100;

// ----------------------------------------------------
// Convert normal matrix into triplet representation
// ----------------------------------------------------

int createTriplet(int matrix[10][10], int rows, int cols,
                  int triplet[MAX][3])
{
    int k = 1;

    triplet[0][0] = rows;
    triplet[0][1] = cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];

                k++;
            }
        }
    }

    triplet[0][2] = k - 1;

    return k;
}

// ----------------------------------------------------
// Display triplet representation
// ----------------------------------------------------

void displayTriplet(int triplet[MAX][3])
{
    int nonZero = triplet[0][2];

    cout << "\nRow\tColumn\tValue\n";

    for (int i = 0; i <= nonZero; i++)
    {
        cout << triplet[i][0] << "\t"
             << triplet[i][1] << "\t"
             << triplet[i][2] << endl;
    }
}

// ----------------------------------------------------
// Transpose of sparse matrix
// ----------------------------------------------------

void transpose(int triplet[MAX][3], int result[MAX][3])
{
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonZero = triplet[0][2];

    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = nonZero;

    int k = 1;

    for (int col = 0; col < cols; col++)
    {
        for (int i = 1; i <= nonZero; i++)
        {
            if (triplet[i][1] == col)
            {
                result[k][0] = triplet[i][1];
                result[k][1] = triplet[i][0];
                result[k][2] = triplet[i][2];

                k++;
            }
        }
    }
}

// ----------------------------------------------------
// Convert triplet back to normal matrix
// ----------------------------------------------------

void tripletToMatrix(int triplet[MAX][3], int matrix[10][10])
{
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonZero = triplet[0][2];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= nonZero; i++)
    {
        matrix[triplet[i][0]][triplet[i][1]] = triplet[i][2];
    }
}

// ----------------------------------------------------
// Display normal matrix
// ----------------------------------------------------

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

// ----------------------------------------------------
// MAIN
// ----------------------------------------------------

int main()
{
    int choice;

    cout << "===== SPARSE MATRIX USING TRIPLET =====\n";

    cout << "\n1. Transpose";
    cout << "\n2. Addition";
    cout << "\n3. Multiplication";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    // =================================================
    // 1. TRANSPOSE
    // =================================================

    if (choice == 1)
    {
        int matrix[10][10];
        int triplet[MAX][3];
        int result[MAX][3];

        int rows, cols;

        cout << "\nEnter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows < 1 || rows > 10 ||
            cols < 1 || cols > 10)
        {
            cout << "Invalid matrix size.\n";
            return 0;
        }

        cout << "\nEnter matrix elements:\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i][j];
            }
        }

        createTriplet(matrix, rows, cols, triplet);

        cout << "\nOriginal Triplet Representation:\n";
        displayTriplet(triplet);

        transpose(triplet, result);

        cout << "\nTranspose Triplet Representation:\n";
        displayTriplet(result);
    }

    // =================================================
    // 2. ADDITION
    // =================================================

    else if (choice == 2)
    {
        int A[10][10], B[10][10], result[10][10];

        int r1, c1, r2, c2;

        cout << "\nEnter rows and columns of first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns of second matrix: ";
        cin >> r2 >> c2;

        if (r1 != r2 || c1 != c2)
        {
            cout << "\nMatrix addition is not possible.\n";
            cout << "Both matrices must have the same dimensions.\n";
            return 0;
        }

        cout << "\nEnter first sparse matrix:\n";

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cin >> A[i][j];
            }
        }

        cout << "\nEnter second sparse matrix:\n";

        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cin >> B[i][j];
            }
        }

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                result[i][j] = A[i][j] + B[i][j];
            }
        }

        cout << "\nResult of Matrix Addition:\n";
        displayMatrix(result, r1, c1);
    }

    // =================================================
    // 3. MULTIPLICATION
    // =================================================

    else if (choice == 3)
    {
        int A[10][10], B[10][10], result[10][10];

        int r1, c1, r2, c2;

        cout << "\nEnter rows and columns of first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns of second matrix: ";
        cin >> r2 >> c2;

        if (c1 != r2)
        {
            cout << "\nMatrix multiplication is not possible.\n";
            cout << "Columns of first matrix must equal rows of second matrix.\n";
            return 0;
        }

        cout << "\nEnter first sparse matrix:\n";

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cin >> A[i][j];
            }
        }

        cout << "\nEnter second sparse matrix:\n";

        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cin >> B[i][j];
            }
        }

        // Initialize result matrix
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                result[i][j] = 0;
            }
        }

        // Matrix multiplication
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "\nResult of Matrix Multiplication:\n";
        displayMatrix(result, r1, c2);
    }

    else
    {
        cout << "\nInvalid choice. Please choose between 1 and 3.\n";
    }

    return 0;
}