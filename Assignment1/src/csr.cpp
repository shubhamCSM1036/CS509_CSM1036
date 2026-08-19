#include "../include/csr.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

CSRGraph readGraph(
    const string& filename,
    int* source,
    bool undirectedEdgeCount
)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error opening file.\n";
        exit(1);
    }

    CSRGraph graph;

    file >> graph.vertices >> graph.edges;

    if (!file || graph.vertices < 0 || graph.edges < 0)
    {
        cerr << "Invalid graph header.\n";
        exit(1);
    }

    graph.row_ptr.push_back(0);

    int current_index = 0;

    for (int i = 0; i < graph.vertices; i++)
    {
        int vertex;
        int degree;

        file >> vertex >> degree;

        if (!file)
        {
            cerr << "Invalid graph input.\n";
            exit(1);
        }

        if (vertex != i)
        {
            cerr << "Invalid vertex numbering.\n";
            exit(1);
        }

        if (degree < 0)
        {
            cerr << "Invalid vertex degree.\n";
            exit(1);
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;
            int weight;

            file >> neighbour >> weight;

            if (!file)
            {
                cerr << "Invalid edge data.\n";
                exit(1);
            }

            if (neighbour < 0 || neighbour >= graph.vertices)
            {
                cerr << "Invalid neighbour vertex.\n";
                exit(1);
            }

            graph.col_idx.push_back(neighbour);
            graph.values.push_back(weight);

            current_index++;
        }

        graph.row_ptr.push_back(current_index);
    }

    int expected_edges = graph.edges;

    if (undirectedEdgeCount)
    {
        expected_edges *= 2;
    }

    if (current_index != expected_edges)
    {
        cerr << "Edge count does not match input.\n";
        exit(1);
    }

    if (source != nullptr)
    {
        string label;

        file >> label >> *source;

        if (!file || label != "SOURCE")
        {
            cerr << "Invalid or missing SOURCE line.\n";
            exit(1);
        }

        if (*source < 0 || *source >= graph.vertices)
        {
            cerr << "Invalid source vertex.\n";
            exit(1);
        }
    }

    return graph;
}

void printCSR(const CSRGraph& graph)
{
    cout << "\nRow Pointer:\n";

    for (int value : graph.row_ptr)
    {
        cout << value << " ";
    }

    cout << "\n\nColumn Indices:\n";

    for (int value : graph.col_idx)
    {
        cout << value << " ";
    }

    cout << "\n\nValues:\n";

    for (int value : graph.values)
    {
        cout << value << " ";
    }

    cout << "\n";
}