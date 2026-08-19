#include <iostream>

#include "../include/assignment3.h"

using namespace std;

void assignment3_func()
{
    cout << "\n===== CS509 - ASSIGNMENT 3 =====\n";
    cout << "1. Kruskal's MST\n";
    cout << "2. Prim's MST\n";
    cout << "3. Run Both MST Algorithms\n";
    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Kruskal's MST is not implemented yet.\n";
        break;

    case 2:
        cout << "Prim's MST is not implemented yet.\n";
        break;

    case 3:
        cout << "MST comparison is not implemented yet.\n";
        break;

    default:
        cout << "Invalid choice.\n";
        break;
    }
}