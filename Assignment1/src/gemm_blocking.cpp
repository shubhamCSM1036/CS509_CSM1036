#include "../include/gemm_blocking.h"

using namespace std;

const int tile_size = 3;

void gemm_blocking(string filename)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error opening input file.\n";
        return;
    }

    int row1, common, col2;

    file >> row1 >> common >> col2;

    vector<vector<int>> matrix1(
        row1,
        vector<int>(common, 0)
    );

    vector<vector<int>> matrix2(
        common,
        vector<int>(col2, 0)
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

    vector<vector<int>> result(
        row1,
        vector<int>(col2, 0)
    );

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < row1; i += tile_size)
    {
        int end_i = min(i + tile_size, row1);

        for (int j = 0; j < col2; j += tile_size)
        {
            int end_j = min(j + tile_size, col2);

            for (int k = 0; k < common; k += tile_size)
            {
                int end_k = min(k + tile_size, common);

                for (int row = i; row < end_i; row++)
                {
                    for (int inner = k; inner < end_k; inner++)
                    {
                        for (int col = j; col < end_j; col++)
                        {
                            result[row][col] +=
                                matrix1[row][inner] *
                                matrix2[inner][col];
                        }
                    }
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(
            end - start
        );

    cout << "\nAlgorithm: GEMM Blocking\n";
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