#include "../include/floyd_warshall.h"

#include <climits>

using namespace std;

bool floydWarshall(
    vector<vector<long long>>& distance
)
{
    const long long INF = LLONG_MAX / 4;

    int vertices = static_cast<int>(distance.size());

    // Floyd-Warshall relaxation.
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            if (distance[i][k] == INF)
            {
                continue;
            }

            for (int j = 0; j < vertices; j++)
            {
                if (distance[k][j] == INF)
                {
                    continue;
                }

                if (distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] =
                        distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // A negative value on the diagonal indicates
    // a negative cycle.
    for (int i = 0; i < vertices; i++)
    {
        if (distance[i][i] < 0)
        {
            return false;
        }
    }

    return true;
}