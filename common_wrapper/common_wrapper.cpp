#include <iostream>

#include "../Assignment1/include/main_driver.h"
#include "../Assignment2/include/assignment2.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n===== CS509 LAB WRAPPER =====\n";
        cout << "1. Assignment 1\n";
        cout << "2. Assignment 2\n";
        cout << "0. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            assignment1_func();
            break;

        case 2:
            assignment2_func();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}