#include <iostream>

#include "../include/assignment3.h"
#include "../include/mst.h"

using namespace std;

static void printMSTResult(
    const string& algorithmName,
    const MSTResult& result
)
{
    cout << "\nAlgorithm: " << algorithmName << "\n";
    cout << "MST edges:\n";

    for (const MSTEdge& edge : result.edges)
    {
        cout << edge.u << " "
             << edge.v << " "
             << edge.weight << "\n";
    }

    cout << "Total MST weight: "
         << result.totalWeight << "\n";
}

void assignment3_func()
{
    cout << "\n===== CS509 - ASSIGNMENT 3 =====\n";
    cout << "1. Kruskal's MST\n";
    cout << "2. Prim's MST\n";
    cout << "3. Run Both MST Algorithms\n";
    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;

    CSRGraph graph = readGraph(
        "Assignment3/tests/mst/mst_test.txt",
        nullptr,
        true
    );

    switch (choice)
    {
    case 1:
    {
        MSTResult result = kruskalMST(graph);

        printMSTResult(
            "Kruskal's MST",
            result
        );

        break;
    }

    case 2:
    {
        MSTResult result = primMST(graph);

        printMSTResult(
            "Prim's MST",
            result
        );

        break;
    }

    case 3:
    {
        MSTResult kruskalResult = kruskalMST(graph);
        MSTResult primResult = primMST(graph);

        printMSTResult(
            "Kruskal's MST",
            kruskalResult
        );

        printMSTResult(
            "Prim's MST",
            primResult
        );

        cout << "\nComparison:\n";
        cout << "Kruskal total weight: "
             << kruskalResult.totalWeight << "\n";

        cout << "Prim total weight: "
             << primResult.totalWeight << "\n";

        cout << "Equal: "
             << (kruskalResult.totalWeight == primResult.totalWeight
                     ? "Yes"
                     : "No")
             << "\n";

        break;
    }

    default:
        cout << "Invalid choice.\n";
        break;
    }
}