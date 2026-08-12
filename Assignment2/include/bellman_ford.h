#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <vector>

#include "../../Assignment1/include/csr.h"

bool bellmanFord(
    const CSRGraph& graph,
    int source,
    std::vector<long long>& distance
);

void runBellmanFord();

#endif