#include "../include/main_driver.h"
#include "../include/csr.h"
#include <iostream>
#include <string>
#include <algorithm>

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
        case 1: {
            int testChoice;

            cout << "\nGEMM Tests:\n";
            cout << "1. gemm_64.txt\n";
            cout << "2. gemm_128.txt\n";
            cout << "3. gemm_256.txt\n";
            cout << "4. gemm_512.txt\n";
            cout << "5. gemm_1024.txt\n";
            cout << "Select test: ";
            cin >> testChoice;

            string filename;

            switch (testChoice) {
                case 1:
                    filename = "Assignment1/tests/gemm/gemm_64.txt";
                    break;
                case 2:
                    filename = "Assignment1/tests/gemm/gemm_128.txt";
                    break;
                case 3:
                    filename = "Assignment1/tests/gemm/gemm_256.txt";
                    break;
                case 4:
                    filename = "Assignment1/tests/gemm/gemm_512.txt";
                    break;
                case 5:
                    filename = "Assignment1/tests/gemm/gemm_1024.txt";
                    break;
                default:
                    cout << "Invalid GEMM test selection.\n";
                    break;
            }

            if (!filename.empty()) {
                gemm_simple(filename);
            }

            break;
        }

        case 2: {
            int testChoice;

            cout << "\nGEMM Tests:\n";
            cout << "1. gemm_64.txt\n";
            cout << "2. gemm_128.txt\n";
            cout << "3. gemm_256.txt\n";
            cout << "4. gemm_512.txt\n";
            cout << "5. gemm_1024.txt\n";
            cout << "Select test: ";
            cin >> testChoice;

            string filename;

            switch (testChoice) {
                case 1:
                    filename = "Assignment1/tests/gemm/gemm_64.txt";
                    break;
                case 2:
                    filename = "Assignment1/tests/gemm/gemm_128.txt";
                    break;
                case 3:
                    filename = "Assignment1/tests/gemm/gemm_256.txt";
                    break;
                case 4:
                    filename = "Assignment1/tests/gemm/gemm_512.txt";
                    break;
                case 5:
                    filename = "Assignment1/tests/gemm/gemm_1024.txt";
                    break;
                default:
                    cout << "Invalid GEMM test selection.\n";
                    break;
            }

            if (!filename.empty()) {
                gemm_blocking(filename);
            }

            break;
        }

        case 3: {
            int testChoice;

            cout << "\nCSR Tests:\n";
            cout << "1. csr_10.txt\n";
            cout << "2. csr_100.txt\n";
            cout << "3. csr_10000.txt\n";
            cout << "4. csr_50000.txt\n";
            cout << "5. csr_100000.txt\n";
            cout << "Select test: ";
            cin >> testChoice;

            string filename;

            switch (testChoice) {
                case 1:
                    filename = "Assignment1/tests/csr/csr_10.txt";
                    break;
                case 2:
                    filename = "Assignment1/tests/csr/csr_100.txt";
                    break;
                case 3:
                    filename = "Assignment1/tests/csr/csr_10000.txt";
                    break;
                case 4:
                    filename = "Assignment1/tests/csr/csr_50000.txt";
                    break;
                case 5:
                    filename = "Assignment1/tests/csr/csr_100000.txt";
                    break;
                default:
                    cout << "Invalid CSR test selection.\n";
                    break;
            }

            if (!filename.empty()) {
                try {
                    CSRGraph graph = readGraph(filename);

                    cout << "\n===== CSR Representation =====\n";

                    cout << "Number of vertices: "
                         << graph.vertices << "\n";

                    cout << "Number of edges: "
                         << graph.edges << "\n";

                    const int preview = 10;

                    cout << "\nCSR arrays:\n";

                    cout << "row_ptr size: "
                         << graph.row_ptr.size() << "\n";

                    cout << "col_idx size: "
                         << graph.col_idx.size() << "\n";

                    cout << "values size: "
                         << graph.values.size() << "\n";

                    cout << "\nrow_ptr preview: ";

                    for (int i = 0;
                         i < min(preview,
                                 static_cast<int>(graph.row_ptr.size()));
                         ++i) {
                        cout << graph.row_ptr[i] << " ";
                    }

                    cout << "\n";

                    cout << "col_idx preview: ";

                    for (int i = 0;
                         i < min(preview,
                                 static_cast<int>(graph.col_idx.size()));
                         ++i) {
                        cout << graph.col_idx[i] << " ";
                    }

                    cout << "\n";

                    cout << "values preview: ";

                    for (int i = 0;
                         i < min(preview,
                                 static_cast<int>(graph.values.size()));
                         ++i) {
                        cout << graph.values[i] << " ";
                    }

                    cout << "\n";
                }
                catch (const exception& e) {
                    cout << "Error reading CSR input: "
                         << e.what() << "\n";
                }
            }

            break;
        }

        default:
            cout << "Invalid choice.\n";
    }
}