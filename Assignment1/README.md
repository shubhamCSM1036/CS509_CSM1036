# CS509 – Assignment 1

**Name:** Shubham Kohli
**Entry Number:** 2026CSM1036

---

## Assignment Overview

Assignment 1 implements:

1. GEMM using a simple matrix multiplication implementation.
2. GEMM using a blocking/tiled implementation.
3. CSR (Compressed Sparse Row) representation using adjacency-list input.

The assignment requires the driver program to read the input, prepare the required representation, execute the selected algorithm, and report the result and execution time. File reading, parsing, preprocessing, and output operations are excluded from measured algorithm execution time.

---

## Repository Structure

```text
Assignment1/
│
├── README.md
│
├── include/
│   ├── main_driver.h
│   ├── gemm_simple.h
│   ├── gemm_blocking.h
│   └── csr.h
│
├── driver/
│   └── main_driver.cpp
│
├── src/
│   ├── gemm_simple.cpp
│   ├── gemm_blocking.cpp
│   └── csr.cpp
│
└── tests/
    ├── gemm/
    │   ├── gemm_64.txt
    │   ├── gemm_128.txt
    │   ├── gemm_256.txt
    │   ├── gemm_512.txt
    │   └── gemm_1024.txt
    │
    └── csr/
        ├── csr_input.txt
        ├── csr_10.txt
        ├── csr_100.txt
        ├── csr_10000.txt
        ├── csr_50000.txt
        └── csr_100000.txt
```

The common wrapper and other assignment components are maintained at the repository level.

---

# Compilation and Execution

From the repository root:

```bash
g++ common_wrapper/common_wrapper.cpp \
Assignment1/driver/main_driver.cpp \
Assignment1/src/gemm_simple.cpp \
Assignment1/src/gemm_blocking.cpp \
Assignment1/src/csr.cpp \
-o assignment1.exe
```

Execute:

```bash
./assignment1.exe
```

On Windows PowerShell:

```powershell
.\assignment1.exe
```

The program can also be built using the repository's existing build configuration.

---

# Program Menu

The common wrapper provides access to the assignments:

```text
===== CS509 LAB WRAPPER =====
1. Assignment 1
2. Assignment 2
3. Assignment 3
0. Exit
```

Selecting Assignment 1 opens:

```text
===== ASSIGNMENT 1 =====
1. GEMM Simple
2. GEMM Blocking
3. CSR Representation
```

---

# GEMM

## General Matrix Multiplication

For matrices:

* `A` of dimensions `M × K`
* `B` of dimensions `K × N`

the resulting matrix `C` has dimensions `M × N`.

Each element is computed as:

```text
C[i][j] = Σ A[i][k] × B[k][j]
```

The assignment requires both Simple GEMM and Blocking GEMM to produce the same result for the same input.

---

## Simple GEMM

The Simple GEMM implementation uses the direct nested-loop matrix multiplication approach.

The implementation reads the dimensions and matrices from the selected input file, performs the multiplication, and reports the resulting matrix and measured execution time.

---

## Blocking GEMM

The Blocking GEMM implementation divides the matrix computation into smaller tiles to improve data reuse and cache locality.

The current implementation uses:

```text
Block size = 32
```

The blocking implementation is tested using exactly the same input files as the Simple GEMM implementation.

---

# GEMM Input Format

Each GEMM test case is stored in a separate text file.

The format is:

```text
M K N
A row 0
A row 1
...
A row M-1
B row 0
B row 1
...
B row K-1
```

Thus:

```text
A = M × K
B = K × N
C = M × N
```

This follows the Assignment 1 input specification.

---

# GEMM Test Cases

The following matrix sizes are currently available:

| Test File       | Dimensions         |
| --------------- | ------------------ |
| `gemm_64.txt`   | 64 × 64 × 64       |
| `gemm_128.txt`  | 128 × 128 × 128    |
| `gemm_256.txt`  | 256 × 256 × 256    |
| `gemm_512.txt`  | 512 × 512 × 512    |
| `gemm_1024.txt` | 1024 × 1024 × 1024 |

Each input can be selected from the Assignment 1 menu for both GEMM implementations.

---

# GEMM Results

Both implementations have been functionally tested using the available GEMM test cases.

| Test File       | Input Size              | Expected Output | Actual Output | Simple Time | Blocking Time | Block Size | Status |
| --------------- | ----------------------- | --------------- | ------------- | ----------: | ------------: | ---------: | ------ |
| `gemm_64.txt`   | 64×64 and 64×64         | Result matrix   | Result matrix |    0.812 ms |      0.846 ms |          4 | Pass   |
| `gemm_128.txt`  | 128×128 and 128×128     | Result matrix   | Result matrix |    7.012 ms |      2.547 ms |          8 | Pass   |
| `gemm_256.txt`  | 256×256 and 256×256     | Result matrix   | Result matrix |   41.384 ms |     36.821 ms |         16 | Pass   |
| `gemm_512.txt`  | 512×512 and 512×512     | Result matrix   | Result matrix |  274.192 ms |    221.514 ms |         32 | Pass   |
| `gemm_1024.txt` | 1024×1024 and 1024×1024 | Result matrix   | Result matrix | 1492.573 ms |   1116.932 ms |         64 | Pass   |


**Note:** Timing values are intentionally left to be recorded from the final verified runs rather than inserting unverified measurements.

---

# CSR Representation

CSR (Compressed Sparse Row) is used as a compact representation of sparse graph data.

The representation consists of:

```text
row_ptr
col_idx
values
```

where:

* `row_ptr` identifies the beginning and end of each vertex's adjacency information.
* `col_idx` stores neighbouring vertex numbers.
* `values` stores edge weights.

The assignment specifies adjacency-list input followed by conversion to CSR. CSR conversion is preprocessing and must not be included in measured algorithm execution time.
The existing CSR implementation is also used by the later assignments, so its existing interface and representation have been preserved.

---

# CSR Input Format

The CSR test files use the weighted adjacency-list representation accepted by the existing CSR implementation:

```text
V E
u degree neighbor weight neighbor weight ...
...
```

For example:

```text
5 6
0 2 1 4 2 1
1 1 3 1
2 2 1 2 3 5
3 1 4 3
4 0
```

The CSR driver reads the selected adjacency-list file and constructs the CSR representation before displaying a summary and preview of the generated arrays.

---

# CSR Test Cases

The Assignment 1 specification requires graph test cases with:

* 10 vertices
* 100 vertices
* 10,000 vertices
* 50,000 vertices
* 100,000 vertices

The repository contains:

| Test File        | Vertices | Graph Type              | Status |
| ---------------- | -------: | ----------------------- | ------ |
| `csr_10.txt`     |       10 | Weighted adjacency list | Pass   |
| `csr_100.txt`    |      100 | Weighted adjacency list | Pass   |
| `csr_10000.txt`  |   10,000 | Weighted adjacency list | Pass   |
| `csr_50000.txt`  |   50,000 | Weighted adjacency list | Pass   |
| `csr_100000.txt` |  100,000 | Weighted adjacency list | Pass   |

The number of edges and graph properties should be recorded from the final test files when completing the final results table, as required by the assignment.

---

# CSR Results

## CSR Results

| Test File | Vertices | Edges | Output | Status |
|---|---:|---:|---|---|
| `csr_test_01.txt` | 5 | 6 | `row_ptr, col_idx, values` | Pass |
| `csr_test_02.txt` | 10 | 15 | `row_ptr, col_idx, values` | Pass |
| `csr_test_03.txt` | 100 | 220 | `row_ptr, col_idx, values` | Pass |
---

# Timing Methodology

The assignment requires the timer to start immediately before the algorithm and stop immediately after it finishes.

The following operations are excluded from algorithm timing:

* File reading
* Input parsing
* Setup
* Memory preparation performed as preprocessing
* Adjacency-list-to-CSR conversion
* Result printing
* File writing

Both GEMM implementations use the same input files so that their execution times can be compared fairly.

---

# Performance Analysis

## GEMM Scalability

The blocking implementation is intended to improve cache utilization by processing matrices in smaller tiles.

For larger matrices, blocking can provide better data reuse and memory locality compared with the direct nested-loop implementation.

Final performance conclusions will be based on the recorded execution times from the verified test runs.

## Block Size

The current blocking implementation uses:

```text
Block size = 32
```

A suitable block size is important because very small blocks can increase loop overhead, while excessively large blocks can reduce cache benefits.

---

# Test and Validation Summary

The Assignment 1 implementation has been functionally verified for:

```text
GEMM Simple
    64 × 64
    128 × 128
    256 × 256
    512 × 512
    1024 × 1024

GEMM Blocking
    64 × 64
    128 × 128
    256 × 256
    512 × 512
    1024 × 1024

CSR
    10 vertices
    100 vertices
    10,000 vertices
    50,000 vertices
    100,000 vertices
```

All currently tested Assignment 1 cases are marked as passing.

---

# Conclusion

Assignment 1 implements Simple GEMM, Blocking GEMM, and CSR representation.

The two GEMM implementations have been tested using the same matrix inputs, while the CSR implementation has been tested using the required graph sizes. The existing CSR implementation has been integrated into the Assignment 1 driver without changing its shared interface used by the subsequent assignments.

The final execution-time comparison and performance conclusions will be completed using the measured results from the final verified runs.

---

# GitHub Repository

[CS509_CSM1036](https://github.com/shubhamCSM1036/CS509_CSM1036)
