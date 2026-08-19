#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "../include/assignment3.h"
#include "../include/mst.h"

using namespace std;
namespace fs = std::filesystem;

static vector<string> getMSTInputFiles()
{
    vector<string> files;

    const fs::path testDirectory = "Assignment3/tests/mst";

    if (!fs::exists(testDirectory))
    {
        return files;
    }

    for (const auto& entry : fs::directory_iterator(testDirectory))
    {
        if (entry.is_regular_file() &&
            entry.path().extension() == ".txt")
        {
            files.push_back(entry.path().filename().string());
        }
    }

    sort(files.begin(), files.end());

    return files;
}

static void printMSTResult(
    const string& algorithmName,
    const MSTResult& result
)
{
    cout << "\nAlgorithm: " << algorithmName << "\n";
    cout << "MST edges:\n";

    for (const MSTEdge& edge : result.edges)
    {
        cout << edge.u << " "
             << edge.v << " "
             << edge.weight << "\n";
    }

    cout << "Total MST weight: "
         << result.totalWeight << "\n";
}

void assignment3_func()
{
    cout << "\n===== CS509 - ASSIGNMENT 3 =====\n";
    cout << "1. Kruskal's MST\n";
    cout << "2. Prim's MST\n";
    cout << "3. Run Both MST Algorithms\n";
    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;

    vector<string> files = getMSTInputFiles();

    if (files.empty())
    {
        cout << "No MST input files found.\n";
        return;
    }

    cout << "\n===== SELECT GRAPH =====\n";

    for (size_t i = 0; i < files.size(); ++i)
    {
        cout << i + 1 << ". " << files[i] << "\n";
    }

    cout << "\nEnter your choice: ";

    int graphChoice;
    cin >> graphChoice;

    if (graphChoice < 1 ||
        graphChoice > static_cast<int>(files.size()))
    {
        cout << "Invalid graph choice.\n";
        return;
    }

    fs::path graphPath =
        fs::path("Assignment3/tests/mst") /
        files[graphChoice - 1];

    CSRGraph graph = readGraph(
        graphPath.string(),
        nullptr,
        true
    );

    switch (choice)
    {
    case 1:
    {
        auto start = chrono::high_resolution_clock::now();

        MSTResult result = kruskalMST(graph);

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        printMSTResult(
            "Kruskal's MST",
            result
        );

        cout << "Execution time: "
            << elapsed.count()
            << " ms\n";

        break;
    }

    case 2:
    {
        auto start = chrono::high_resolution_clock::now();

        MSTResult result = primMST(graph);

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        printMSTResult(
            "Prim's MST",
            result
        );

        cout << "Execution time: "
            << elapsed.count()
            << " ms\n";
        break;
    }

    case 3:
    {
        auto kruskalStart = chrono::high_resolution_clock::now();

        MSTResult kruskalResult = kruskalMST(graph);

        auto kruskalEnd = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> kruskalTime =
            kruskalEnd - kruskalStart;


        auto primStart = chrono::high_resolution_clock::now();

        MSTResult primResult = primMST(graph);

        auto primEnd = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> primTime =
            primEnd - primStart;

        cout << "Kruskal execution time: "
            << kruskalTime.count()
            << " ms\n";

        cout << "Prim execution time: "
            << primTime.count()
            << " ms\n";

        cout << "\nComparison:\n";

        cout << "Kruskal total weight: "
             << kruskalResult.totalWeight << "\n";

        cout << "Prim total weight: "
             << primResult.totalWeight << "\n";

        cout << "Equal: "
             << (kruskalResult.totalWeight == primResult.totalWeight
                     ? "Yes"
                     : "No")
             << "\n";

        break;
    }

    default:
        cout << "Invalid choice.\n";
        break;
    }
}