#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

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
        MSTResult result = kruskalMST(graph);

        printMSTResult(
            "Kruskal's MST",
            result
        );

        break;
    }

    case 2:
    {
        MSTResult result = primMST(graph);

        printMSTResult(
            "Prim's MST",
            result
        );

        break;
    }

    case 3:
    {
        MSTResult kruskalResult = kruskalMST(graph);
        MSTResult primResult = primMST(graph);

        printMSTResult(
            "Kruskal's MST",
            kruskalResult
        );

        printMSTResult(
            "Prim's MST",
            primResult
        );

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