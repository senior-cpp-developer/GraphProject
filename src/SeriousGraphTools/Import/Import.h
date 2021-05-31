#ifndef GRAPHPROJECT_IMPORT_H
#define GRAPHPROJECT_IMPORT_H

#include "../SimpleGraph.h"
#include "../../libs/nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

namespace SeriousGraphTools {
    class Import {
    public:
        static SimpleGraph importFromAdjacencyList (const json& json);
    };
}


#endif //GRAPHPROJECT_IMPORT_H
