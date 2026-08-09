#include <chrono>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

#include "../include/bellman_ford.h"

using namespace std;

void runBellmanFord()
{
    string filename;

    cout << "\n===== BELLMAN-FORD =====\n";
    cout << "Enter input file path: ";
    cin >> filename;

    int source;

    // Input parsing and CSR conversion are preprocessing.
    CSRGraph graph = readGraph(filename, &source);

    vector<long long> distance;

    // Start timing only when the Bellman-Ford algorithm begins.
    auto start = chrono::high_resolution_clock::now();

    bool success = bellmanFord(graph, source, distance);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

    cout << "\nAlgorithm: Bellman-Ford\n";
    cout << "Vertices: " << graph.vertices << "\n";
    cout << "Edges: " << graph.edges << "\n";
    cout << "Source: " << source << "\n";

    cout << "Execution time: "
         << elapsed.count()
         << " ms\n";

    if (!success)
    {
        cout << "Negative cycle: true\n";
        return;
    }

    cout << "\nVertex Distance\n";

    const long long INF = LLONG_MAX / 4;

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
}

int main()
{
    cout << "===== CS509 - ASSIGNMENT 2 =====\n";
    cout << "1. Bellman-Ford\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        runBellmanFord();
        break;

    default:
        cout << "Invalid choice.\n";
        break;
    }

    return 0;
}