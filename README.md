# CS509 – Software Lab

This repository contains the implementations and test cases for the CS509 Software Lab assignments.

## Repository Structure

```text
CS509_CSM1036/
│
├── README.md
│
├── common_wrapper/
│   └── common_wrapper.cpp
│
├── Assignment1/
│   ├── README.md
│   ├── include/
│   ├── driver/
│   ├── src/
│   └── tests/
│
├── Assignment2/
│   ├── README.md
│   ├── include/
│   ├── driver/
│   ├── src/
│   └── tests/
│
└── Assignment3/
    ├── README.md
    ├── include/
    ├── driver/
    ├── src/
    └── tests/
```

---

## Assignments

### Assignment 1

Includes:

* Simple GEMM
* Blocking GEMM
* CSR representation

### Assignment 2

Includes the algorithms and implementations completed for the second assignment.

### Assignment 3

Includes the algorithms and implementations completed for the third assignment.

---

## Compilation

The repository uses a common wrapper to access all three assignments.

From the repository root, compile the project using the project's build configuration:

```bash
make
```

If the project is being compiled manually, use the source files and include directories corresponding to the assignment being tested.

---

## Execution

After compilation, run the generated executable:

### Linux / macOS

```bash
./assignment.exe
```

### Windows PowerShell

```powershell
.\assignment.exe
```

The common wrapper displays:

```text
===== CS509 LAB WRAPPER =====
1. Assignment 1
2. Assignment 2
3. Assignment 3
0. Exit
```

Select the required assignment from the menu.

---

## Assignment 1

Selecting Assignment 1 opens:

```text
===== ASSIGNMENT 1 =====
1. GEMM Simple
2. GEMM Blocking
3. CSR Representation
```

GEMM test files are selected through the program menu.

Available GEMM tests:

```text
gemm_64.txt
gemm_128.txt
gemm_256.txt
gemm_512.txt
gemm_1024.txt
```

CSR test files are also selected through the program menu.

Available CSR tests:

```text
csr_10.txt
csr_100.txt
csr_10000.txt
csr_50000.txt
csr_100000.txt
```

---

## Input Files

Each assignment maintains its test inputs inside its respective `tests/` directory.

```text
Assignment1/tests/
├── gemm/
└── csr/

Assignment2/tests/

Assignment3/tests/
```

Input files are read by the corresponding assignment driver before the selected algorithm is executed.

---

## Execution Timing

Algorithm execution time is measured separately from input preparation.

File reading, input parsing, preprocessing, CSR conversion, and result printing are not included in the reported algorithm execution time where applicable.

This allows the execution times of different implementations to be compared fairly.

---

## Notes

* Each assignment has its own implementation and test files.
* Assignment-specific details and results are maintained in the respective assignment directories.
* The common wrapper provides a single entry point for running the assignments.
* Shared components used by multiple assignments should be modified carefully to preserve compatibility between assignments.

---

## GitHub Repository

[CS509_CSM1036](https://github.com/shubhamCSM1036/CS509_CSM1036)
