#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n===== STRING OPERATIONS =====\n";
        cout << "1. Concatenate Two Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete Vowels from a String\n";
        cout << "4. Sort Characters in Alphabetical Order\n";
        cout << "5. Convert Uppercase Character to Lowercase\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        // -----------------------------------------
        // 1. CONCATENATE TWO STRINGS
        // -----------------------------------------

        if (choice == 1)
        {
            string str1, str2;

            cout << "\nEnter first string: ";
            getline(cin, str1);

            cout << "Enter second string: ";
            getline(cin, str2);

            string result = str1 + str2;

            cout << "Concatenated string: " << result << endl;
        }

        // -----------------------------------------
        // 2. REVERSE A STRING
        // -----------------------------------------

        else if (choice == 2)
        {
            string str;

            cout << "\nEnter a string: ";
            getline(cin, str);

            reverse(str.begin(), str.end());

            cout << "Reversed string: " << str << endl;
        }

        // -----------------------------------------
        // 3. DELETE VOWELS
        // -----------------------------------------

        else if (choice == 3)
        {
            string str;

            cout << "\nEnter a string: ";
            getline(cin, str);

            string result = "";

            for (char ch : str)
            {
                if (ch != 'a' && ch != 'e' && ch != 'i' &&
                    ch != 'o' && ch != 'u' &&
                    ch != 'A' && ch != 'E' && ch != 'I' &&
                    ch != 'O' && ch != 'U')
                {
                    result += ch;
                }
            }

            cout << "String after deleting vowels: "
                 << result << endl;
        }

        // -----------------------------------------
        // 4. SORT CHARACTERS
        // -----------------------------------------

        else if (choice == 4)
        {
            string str;

            cout << "\nEnter a string: ";
            getline(cin, str);

            sort(str.begin(), str.end());

            cout << "String after sorting characters: "
                 << str << endl;
        }

        // -----------------------------------------
        // 5. UPPERCASE TO LOWERCASE
        // -----------------------------------------

        else if (choice == 5)
        {
            char ch;

            cout << "\nEnter an uppercase character: ";
            cin >> ch;

            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 32;

                cout << "Lowercase character: "
                     << ch << endl;
            }
            else
            {
                cout << "Please enter an uppercase character."
                     << endl;
            }
        }

        // -----------------------------------------
        // 6. EXIT
        // -----------------------------------------

        else if (choice == 6)
        {
            cout << "\nExiting program..." << endl;
        }

        else
        {
            cout << "\nInvalid choice. Please try again."
                 << endl;
        }

    } while (choice != 6);

    return 0;
}