#include "mst.h"

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    explicit DSU(int n)
        : parent(n), rank(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
        {
            return false;
        }

        if (rank[a] < rank[b])
        {
            swap(a, b);
        }

        parent[b] = a;

        if (rank[a] == rank[b])
        {
            rank[a]++;
        }

        return true;
    }
};

MSTResult kruskalMST(const CSRGraph& graph)
{
    MSTResult result;
    result.totalWeight = 0;

    vector<MSTEdge> edges;

    // Extract each undirected edge only once.
    for (int u = 0; u < graph.vertices; ++u)
    {
        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; ++i)
        {
            int v = graph.col_idx[i];
            int weight = graph.values[i];

            if (u < v)
            {
                edges.push_back({u, v, weight});
            }
        }
    }

    // Sort edges by non-decreasing weight.
    sort(edges.begin(), edges.end(),
         [](const MSTEdge& a, const MSTEdge& b)
         {
             return a.weight < b.weight;
         });

    DSU dsu(graph.vertices);

    // Select edges that do not create a cycle.
    for (const MSTEdge& edge : edges)
    {
        if (dsu.unite(edge.u, edge.v))
        {
            result.edges.push_back(edge);
            result.totalWeight += edge.weight;

            if (static_cast<int>(result.edges.size()) == graph.vertices - 1)
            {
                break;
            }
        }
    }

    return result;
}