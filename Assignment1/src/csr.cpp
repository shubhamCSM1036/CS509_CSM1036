#include "../include/csr.h"

using namespace std;

CSRGraph readGraph(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error opening file.\n";
        exit(1);
    }

    CSRGraph graph;

    file >> graph.vertices >> graph.edges;

    graph.row_ptr.push_back(0);

    int current_index = 0;

    for (int i = 0; i < graph.vertices; i++)
    {
        int vertex;
        int degree;

        file >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour;
            int weight;

            file >> neighbour >> weight;

            graph.col_idx.push_back(neighbour);
            graph.values.push_back(weight);

            current_index++;
        }

        graph.row_ptr.push_back(current_index);
    }

    file.close();

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

void runCSR()
{
    CSRGraph graph = readGraph("tests/csr/csr_input.txt");

    printCSR(graph);
}