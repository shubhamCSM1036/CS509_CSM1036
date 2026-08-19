#ifndef MST_H
#define MST_H

#include "csr.h"

struct MSTEdge
{
    int u;
    int v;
    int weight;
};

struct MSTResult
{
    std::vector<MSTEdge> edges;
    long long totalWeight;
};

MSTResult kruskalMST(const CSRGraph& graph);
MSTResult primMST(const CSRGraph& graph);

#endif