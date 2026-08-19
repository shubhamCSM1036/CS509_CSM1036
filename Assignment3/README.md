# CS509 – Assignment 3

## Minimum Spanning Tree (MST)

This repository contains the implementation of the **individual component of CS509 Assignment 3**.

The individual task for this assignment is the implementation and comparison of:

- Kruskal's Minimum Spanning Tree algorithm
- Prim's Minimum Spanning Tree algorithm

Both algorithms operate on the same **weighted, undirected CSR graph**.

---

## Assignment Objective

The objective of this assignment is to implement two Minimum Spanning Tree algorithms and compare their correctness and execution performance.

The required algorithms are:

1. **Kruskal's Algorithm**
2. **Prim's Algorithm**

For the same input graph, both algorithms must produce the same minimum total MST weight. When multiple MSTs exist, the selected edges may differ as long as the total weight is minimum.

---

## Project Structure

```text
Assignment3/
│
├── driver/
│   └── main.cpp
│
├── include/
│   ├── assignment3.h
│   ├── mst.h
│   └── mst_input.h
│
├── src/
│   ├── mst.cpp
│   └── mst_input.cpp
│
└── tests/
    └── mst/
        ├── mst_10.txt
        ├── mst_100.txt
        ├── mst_10000.txt
        ├── mst_50000.txt
        └── mst_100000.txt
```

## Results

Both Kruskal's and Prim's algorithms were tested using the five required MST graph sizes.

| Test Case | Vertices (V) | Edges (E) | MST Weight | Kruskal Time (ms) | Prim Time (ms) |
|-----------|-------------:|----------:|-----------:|------------------:|---------------:|
| `mst_10.txt` | 10 | 20 | 16,300 | 0.0094 | 0.0072 |
| `mst_100.txt` | 100 | 200 | 205,184 | 0.0319 | 0.0336 |
| `mst_10000.txt` | 10,000 | 20,000 | 21,439,203 | 1.9271 | 2.9273 |
| `mst_50000.txt` | 50,000 | 100,000 | 107,100,824 | 13.3285 | 17.8311 |
| `mst_100000.txt` | 100,000 | 200,000 | 213,338,518 | 19.0503 | 37.6381 |

### Result Verification

- Both algorithms produced exactly `V - 1` MST edges for every test case.
- Kruskal's and Prim's algorithms produced the same total MST weight for every graph.
- All five required graph sizes completed successfully.
- The largest test case contained 100,000 vertices and 200,000 edges.
- The test graphs use `E = 2V`, keeping the larger graphs sparse.
- Execution time was measured only for the algorithm execution and excluded file reading, input preparation, CSR conversion, and output.

All test cases passed successfully.

## Performance Summary

| Test Case | Kruskal Time (ms) | Prim Time (ms) | Faster Algorithm |
|-----------|------------------:|---------------:|------------------|
| `mst_10.txt` | 0.0094 | 0.0072 | Prim |
| `mst_100.txt` | 0.0319 | 0.0336 | Kruskal |
| `mst_10000.txt` | 1.9271 | 2.9273 | Kruskal |
| `mst_50000.txt` | 13.3285 | 17.8311 | Kruskal |
| `mst_100000.txt` | 19.0503 | 37.6381 | Kruskal |

For the smallest graph, Prim's algorithm was slightly faster. As the graph size increased, Kruskal's algorithm consistently required less execution time than Prim's algorithm in the measured runs.

At 100,000 vertices, Kruskal completed in 19.0503 ms compared with 37.6381 ms for Prim.

The observed results are machine-dependent, but across these five benchmark graphs, Kruskal showed better measured performance on the larger sparse graphs.

## Conclusion

The Assignment 3 individual task successfully implements both required Minimum Spanning Tree algorithms: Kruskal's algorithm and Prim's algorithm.

Kruskal's algorithm uses edge sorting and DSU-based cycle detection, while Prim's algorithm grows the MST using a min-priority queue. Both implementations operate on the CSR graph representation and were tested using the five required graph sizes: 10, 100, 10,000, 50,000, and 100,000 vertices.

All five test cases successfully produced a valid spanning tree containing `V - 1` edges. The total MST weight produced by Kruskal's and Prim's algorithms matched for every test case, confirming the correctness of both implementations.

The execution-time results show that Prim's algorithm was slightly faster for the smallest test case, while Kruskal's algorithm performed better on the larger graphs. For the largest 100,000-vertex graph, Kruskal completed in `19.0503 ms`, compared with `37.6381 ms` for Prim.

Overall, the implementation satisfies the required MST functionality, correctness checks, CSR-based input flow, and performance evaluation requirements of Assignment 3.
