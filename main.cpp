#include <iostream>
#include <fstream>
#include "src/libs/nlohmann/json.hpp"
#include "src/SeriousGraphTools/SimpleGraph.h"
#include "src/SeriousGraphTools/IO/Import.h"
#include "src/SeriousGraphTools/IO/Export.h"
#include "src/SeriousGraphTools/Alghoritms.h"

// for convenience
using json = nlohmann::json;
namespace sgt = SeriousGraphTools;

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    sgt::SimpleGraph test;
    test.addAutoNodes(4);
    test.connect(0, 2, 1, false);

    cout << "Importing graph from adjacency list \"graph-flow.json\"..." << endl;
    std::ifstream inputFile("graph-flow.json");
    json inputJSON;
    sgt::SimpleGraph graph;
    try {
        inputFile >> inputJSON;
    }
    catch (json::exception & e) {
        std::cout << "There's something wrong with your JSON!" << std::endl;
        std::cout << e.what() << std::endl;
        exit(-1);
    }
    try {
        graph = sgt::Import::importFromAdjacencyList(inputJSON);
    }
    catch (...) {
        std::cout << "There's a problem with importing your graph. Maybe check later? Dunno " << std::endl;
        exit(-1);
    }
    cout << endl;
    cout << "Graph stats ------------" << endl;
    cout << "Number of nodes: " << graph.getNodes().size() << endl;
    cout << "Number of edges: " << graph.getEdges().size() << endl;
    graph.simplify();
    cout << "This graph is" << (graph.isOriented() ? " " : " not ") << "oriented" << endl << endl;

    double maxflow = sgt::Alghoritms::edmondsKarp(graph, 0, 6);
    cout << "Edmonds-Karp's algorithm has concluded that this graph has maximum flow of: " << maxflow << endl;

    return 0;
}
