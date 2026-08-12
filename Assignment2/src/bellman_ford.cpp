#include <chrono>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

#include "../include/bellman_ford.h"

using namespace std;

const long long INF = LLONG_MAX / 4;

void runBellmanFord()
{
    const string directory =
        "Assignment2/tests/bellman_ford";

    vector<string> files = {
        "bf_10.txt",
        "bf_100.txt",
        "bf_10000.txt",
        "bf_50000.txt",
        "bf_100000.txt"
    };

    cout << "\n===== BELLMAN-FORD =====\n";
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

    int source;

    CSRGraph graph =
        readGraph(selected_file, &source);

    vector<long long> distance;

    auto start =
        chrono::high_resolution_clock::now();

    bool success =
        bellmanFord(
            graph,
            source,
            distance
        );

    auto end =
        chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed =
        end - start;

    cout << "\nAlgorithm: Bellman-Ford\n";
    cout << "Vertices: " << graph.vertices << "\n";
    cout << "Edges: " << graph.edges << "\n";
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

bool bellmanFord(
    const CSRGraph& graph,
    int source,
    vector<long long>& distance
)
{
    const long long INF = LLONG_MAX / 4;

    int vertices = graph.vertices;

    distance.assign(vertices, INF);
    distance[source] = 0;

    // Relax all edges V - 1 times.
    for (int i = 0; i < vertices - 1; i++)
    {
        bool updated = false;

        for (int u = 0; u < vertices; u++)
        {
            if (distance[u] == INF)
            {
                continue;
            }

            for (int j = graph.row_ptr[u];
                 j < graph.row_ptr[u + 1];
                 j++)
            {
                int v = graph.col_idx[j];
                int weight = graph.values[j];

                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    updated = true;
                }
            }
        }
        if (!updated)
        {
            break;
        }
    }

    for (int u = 0; u < vertices; u++)
    {
        if (distance[u] == INF)
        {
            continue;
        }

        for (int j = graph.row_ptr[u];
             j < graph.row_ptr[u + 1];
             j++)
        {
            int v = graph.col_idx[j];
            int weight = graph.values[j];

            if (distance[u] + weight < distance[v])
            {
                return false;
            }
        }
    }

    return true;
}