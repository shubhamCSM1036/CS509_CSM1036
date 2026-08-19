#include <iostream>

#include "../include/assignment3.h"
#include "../include/mst.h"

using namespace std;

void assignment3_func()
{
    cout << "\n===== CS509 - ASSIGNMENT 3 =====\n";

    CSRGraph graph = readGraph(
        "Assignment3/tests/mst/mst_test.txt",
        nullptr,
        true
    );

    MSTResult result = primMST(graph);

    cout << "\nAlgorithm: Prim's MST\n";
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