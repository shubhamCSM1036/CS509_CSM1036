#include <iostream>

#include "../include/assignment2.h"
#include "../include/bellman_ford.h"
#include "../include/floyd_warshall.h"

using namespace std;

void assignment2_func()
{
    cout << "\n===== CS509 - ASSIGNMENT 2 =====\n";
    cout << "1. Bellman-Ford\n";
    cout << "2. Floyd-Warshall\n";
    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        runBellmanFord();
        break;

    case 2:
        runFloydWarshall();
        break;

    default:
        cout << "Invalid choice.\n";
        break;
    }
}