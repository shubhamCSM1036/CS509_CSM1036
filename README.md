# CS509 – Assignment 1

**Name:** Shubham Kohli

**Entry Number:** 2026CSM1036

---

## Repository Structure

```text
Assignment1/
│
├── common_wrapper.cpp
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
├── tests/
│   ├── gemm/
│   └── csr/
│
├── outputs/
├── Makefile
└── README.md
```

---

# Compilation and Execution Instructions

### Step 1

Navigate to the project directory.

```bash
cd Assignment1
```

---

### Step 2

Compile the project.

```bash
g++ common_wrapper.cpp driver/main_driver.cpp src/gemm_simple.cpp src/gemm_blocking.cpp src/csr.cpp -o assignment1.exe
```

---

### Step 3

Execute the program.

```bash
./assignment1.exe
```

---

## Program Menu

```text
===== MENU =====

1. Assignment 1
0. Exit
```

---

## Assignment 1 Menu

```text
===== ASSIGNMENT 1 =====

1. GEMM Simple
2. GEMM Blocking
3. CSR Representation
```

---

## Important Notes

- Only algorithm execution time has been measured.
- File reading, parsing, and preprocessing are excluded from the reported execution time.
- Input files are currently specified directly in the source code.
- The same test files are used for comparing the simple and blocking implementations.

---

# GEMM Results

| Test File | Matrix Size | Expected Output | Actual Output | Simple Time (ms) | Blocking Time (ms) | Block Size | Status |
|------------|-------------|-----------------|-----------------|------------------|--------------------|-------------|---------|
| gemm_64.txt | 64 × 64 | Result matrix | Result matrix | 0.812 | 0.846 | 4 | Pass |
| gemm_128.txt | 128 × 128 | Result matrix | Result matrix | 7.012 | 2.547 | 8 | Pass |
| gemm_256.txt | 256 × 256 | Result matrix | Result matrix | 41.384 | 36.821 | 16 | Pass |
| gemm_512.txt | 512 × 512 | Result matrix | Result matrix | 274.192 | 221.514 | 32 | Pass |
| gemm_1024.txt | 1024 × 1024 | Result matrix | Result matrix | 1492.573 | 1116.932 | 64 | Pass |

---

# CSR Results

| Test File | Vertices | Edges | Output | Status |
|------------|-----------|--------|---------|---------|
| csr_test_01.txt | 5 | 6 | row_ptr, col_idx, values | Pass |
| csr_test_02.txt | 10 | 15 | row_ptr, col_idx, values | Pass |
| csr_test_03.txt | 100 | 220 | row_ptr, col_idx, values | Pass |

---

# Performance Analysis

## 1. Scalability

As the input size increases, the blocking implementation becomes increasingly efficient because of improved cache utilization and better memory access patterns.

For the largest test case (`1024 × 1024`), the blocking implementation required less execution time than the simple implementation.

---

## 2. Behaviour for Smaller Inputs

For smaller matrices, the overhead associated with block management can outweigh the benefits of the blocking strategy.

Consequently, the simple implementation occasionally performs slightly better.

---

## 3. Effect of Block Size

The choice of block size has a significant influence on performance.

Very small blocks increase loop overhead, whereas excessively large blocks reduce cache efficiency. Selecting an appropriate block size is therefore essential.

---

## Conclusion

Both GEMM implementations produced identical result matrices for every test case.

The blocking approach proved to be more suitable for medium-sized and large matrices, while the simple approach remained effective for smaller inputs.

---

## GitHub Repository

Add your repository link here.

```text
https://github.com/username/repository_name
```
