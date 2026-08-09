#include <climits>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/bellman_ford.h"
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

void runBellmanFord()
{
    string filename;

    cout << "\n===== BELLMAN-FORD =====\n";
    cout << "Enter input file path: ";
    cin >> filename;

    int source;

    // File reading and CSR conversion are preprocessing.
    CSRGraph graph = readGraph(filename, &source);

    vector<long long> distance;

    // Algorithm timing starts here.
    auto start = chrono::high_resolution_clock::now();

    bool success = bellmanFord(
        graph,
        source,
        distance
    );

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

    cout << "\nAlgorithm: Bellman-Ford\n";
    cout << "Source: " << source << "\n";

    if (!success)
    {
        cout << "Negative cycle: true\n";
        cout << "Execution time: "
             << elapsed.count()
             << " ms\n";

        return;
    }

    cout << "Vertex Distance\n";

    for (int i = 0; i < graph.vertices; i++)
    {
        cout << i << " ";

        if (distance[i] == INF)
        {
            cout << "INF";
        }
        else
        {
            cout << distance[i];
        }

        cout << "\n";
    }

    cout << "Negative cycle: none\n";

    cout << "Execution time: "
         << elapsed.count()
         << " ms\n";
}

void runFloydWarshall()
{
    string filename;

    cout << "\n===== FLOYD-WARSHALL =====\n";
    cout << "Enter input file path: ";
    cin >> filename;

    vector<vector<long long>> distance;

    // Matrix construction is preprocessing.
    if (!readFloydWarshallInput(filename, distance))
    {
        return;
    }

    // Algorithm timing starts after matrix construction.
    auto start = chrono::high_resolution_clock::now();

    bool success = floydWarshall(distance);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

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
        for (int j = 0; j < static_cast<int>(row.size()); j++)
        {
            if (row[j] == INF)
            {
                cout << "INF";
            }
            else
            {
                cout << row[j];
            }

            if (j + 1 < static_cast<int>(row.size()))
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

int main()
{
    cout << "===== CS509 - ASSIGNMENT 2 =====\n";
    cout << "1. Bellman-Ford\n";
    cout << "2. Floyd-Warshall\n";
    cout << "Enter your choice: ";

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

    return 0;
}