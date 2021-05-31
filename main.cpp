#include <iostream>
#include "src/libs/nlohmann/json.hpp"
#include "src/SeriousGraphTools/SimpleGraph.h"

// for convenience
using json = nlohmann::json;
namespace sgt = SeriousGraphTools;

int main() {
    std::cout << "Hello, World!" << std::endl;

    sgt::SimpleGraph<void> graph;


    return 0;
}
