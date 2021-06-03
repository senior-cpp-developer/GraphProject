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

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    string fileLocation = "graph-flow.json";
    if (argc == 2)
        fileLocation = string(argv[1]);

    cout << "Importing graph from adjacency list \"" << fileLocation << "\"..." << endl;
    std::ifstream inputFile(fileLocation);
    if (inputFile.fail()) {
        cout << "Can't open the file!" << endl;
        exit(-1);
    }
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
