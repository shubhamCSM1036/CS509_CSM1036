#ifndef CSR_H
#define CSR_H

#include <string>
#include <vector>

struct CSRGraph
{
    int vertices;
    int edges;

    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;
};

CSRGraph readGraph(
    const std::string& filename,
    int* source = nullptr,
    bool undirectedEdgeCount = false
);

void printCSR(const CSRGraph& graph);

#endif