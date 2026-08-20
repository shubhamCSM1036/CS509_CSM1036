#include "../include/gemm_simple.h"

using namespace std;

void gemm_simple(string filename)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error opening input file.\n";
        return;
    }

    int row1, common, col2;

    file >> row1 >> common >> col2;

    vector<vector<long long>> matrix1(
        row1,
        vector<long long>(common, 0)
    );

    vector<vector<long long>> matrix2(
        common,
        vector<long long>(col2, 0)
    );

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < common; j++)
        {
            file >> matrix1[i][j];
        }
    }

    for (int i = 0; i < common; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            file >> matrix2[i][j];
        }
    }

    file.close();

    vector<vector<long long>> result(
        row1,
        vector<long long>(col2, 0)
    );

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < common; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(
            end - start
        );

    cout << "\nAlgorithm: GEMM Simple\n";
    cout << "\nResult Matrix:\n";

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << result[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "\nExecution time: "
         << duration.count()
         << " microseconds\n";
}