#include <iostream>
#include <fstream>
#include "src/libs/nlohmann/json.hpp"
#include "src/SeriousGraphTools/SimpleGraph.h"
#include "src/SeriousGraphTools/Import/Import.h"

// for convenience
using json = nlohmann::json;
namespace sgt = SeriousGraphTools;

int main() {
    std::cout << "Hello, World!" << std::endl;

    sgt::SimpleGraph test;
    test.addAutoNodes(4);
    test.connect(0, 2, 1);

    std::ifstream inputFile("graph.json");
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

    graph = sgt::Import::importFromAdjacencyList(inputJSON);

    return 0;
}
