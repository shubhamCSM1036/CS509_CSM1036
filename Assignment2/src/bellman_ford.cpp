#include "../include/bellman_ford.h"

#include <climits>

using namespace std;

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

        // If no distance changed during a complete pass,
        // no further relaxation is possible.
        if (!updated)
        {
            break;
        }
    }

    // One additional pass for negative-cycle detection.
    // Only cycles reachable from the source matter.
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