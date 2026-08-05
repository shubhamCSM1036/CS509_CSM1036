#include "../include/main_driver.h"

using namespace std;

void main_driver()
{
    int choice;

    cout << "\n===== ASSIGNMENT 1 =====\n";
    cout << "1. GEMM Simple\n";
    cout << "2. GEMM Blocking\n";
    cout << "3. CSR Representation\n";
    cout << "Enter your choice: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        gemm_simple("tests/gemm/gemm_64.txt");
        break;

    case 2:
        gemm_blocking("tests/gemm/gemm_64.txt");
        break;

    case 3:
        runCSR();
        break;

    default:
        cout << "Invalid choice.\n";
    }
}

