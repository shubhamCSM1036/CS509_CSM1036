#include <chrono>
#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/floyd_warshall.h"

using namespace std;

const long long INF = LLONG_MAX / 4;

bool readFloydWarshallInput(
    const string& filename,
    vector<vector<long long>>& distance
)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error opening file.\n";
        return false;
    }

    int vertices;

    file >> vertices;

    if (!file || vertices <= 0)
    {
        cerr << "Invalid number of vertices.\n";
        return false;
    }

    distance.assign(
        vertices,
        vector<long long>(vertices, INF)
    );

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            string value;

            file >> value;

            if (!file)
            {
                cerr << "Invalid matrix input.\n";
                return false;
            }

            if (value == "INF")
            {
                distance[i][j] = INF;
            }
            else
            {
                try
                {
                    distance[i][j] = stoll(value);
                }
                catch (...)
                {
                    cerr << "Invalid matrix value.\n";
                    return false;
                }
            }
        }
    }

    return true;
}

bool floydWarshall(
    vector<vector<long long>>& distance
)
{
    int vertices = static_cast<int>(distance.size());

    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            if (distance[i][k] == INF)
            {
                continue;
            }

            for (int j = 0; j < vertices; j++)
            {
                if (distance[k][j] == INF)
                {
                    continue;
                }

                if (distance[i][k] + distance[k][j] <
                    distance[i][j])
                {
                    distance[i][j] =
                        distance[i][k] + distance[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (distance[i][i] < 0)
        {
            return false;
        }
    }

    return true;
}

void runFloydWarshall()
{
    const string directory =
        "Assignment2/tests/floyd_warshall";

    vector<string> files = {
        "fw_10.txt",
        "fw_100.txt",
        "fw_500.txt",
        "fw_1000.txt",
        "fw_2000.txt"
    };

    cout << "\n===== FLOYD-WARSHALL =====\n";
    cout << "\nSelect a graph file:\n";

    for (size_t i = 0; i < files.size(); ++i)
    {
        cout << i + 1 << ". "
             << files[i] << "\n";
    }

    int choice;

    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice < 1 ||
        choice > static_cast<int>(files.size()))
    {
        cout << "Invalid choice.\n";
        return;
    }

    string selected_file =
        directory + "/" + files[choice - 1];

    vector<vector<long long>> distance;

    if (!readFloydWarshallInput(
            selected_file,
            distance))
    {
        return;
    }

    auto start =
        chrono::high_resolution_clock::now();

    bool success =
        floydWarshall(distance);

    auto end =
        chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed =
        end - start;

    cout << "\nAlgorithm: Floyd-Warshall\n";

    if (!success)
    {
        cout << "Negative cycle: true\n";
        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";

        return;
    }

    cout << "Distance matrix:\n";

    for (const vector<long long>& row : distance)
    {
        for (int j = 0;
             j < static_cast<int>(row.size());
             j++)
        {
            if (row[j] == INF)
            {
                cout << "INF";
            }
            else
            {
                cout << row[j];
            }

            if (j + 1 <
                static_cast<int>(row.size()))
            {
                cout << " ";
            }
        }

        cout << "\n";
    }

    cout << "Negative cycle: none\n";

    cout << "Execution time: "
         << elapsed.count()
         << " ms\n";
}