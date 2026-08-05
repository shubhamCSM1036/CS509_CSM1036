#ifndef CSR_H
#define CSR_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct CSRGraph
{
    int vertices;
    int edges;

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;
};

CSRGraph readGraph(const string& filename);

void printCSR(const CSRGraph& graph);

void runCSR();

#endif