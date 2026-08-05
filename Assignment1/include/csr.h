#ifndef CSR_H
#define CSR_H

#include <vector>
#include <string>

using namespace std;

struct CSRGraph
{
    int vertices;
    int edges;

    vector<int> row_ptr;
    vector<int> col_idx;
};

CSRGraph readGraph(
    const string& filename
);

void printCSR(
    const CSRGraph& graph
);

void runCSR();

#endif