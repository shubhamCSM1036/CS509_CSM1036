#include "main_driver.h"

using namespace std;

void assignment1_func()
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
            gemm_simple("tests/gemm/gemm_test_01.txt");
            break;

        case 2:
            gemm_blocking("tests/gemm/gemm_test_01.txt");
            break;

        case 3:
            CSR_func();
            break;

        default:
            cout << "Invalid choice.\n";
    }
}

int main()
{
    assignment1_func();

    return 0;
}