#ifndef GRAPHPROJECT_EXPORT_H
#define GRAPHPROJECT_EXPORT_H

#include "../../libs/nlohmann/json.hpp"
#include "../SimpleGraph.h"

// for convenience
using json = nlohmann::json;

namespace SeriousGraphTools {
    class Export {
    public:
        static json exportToIncidenceMatrix(const SimpleGraph &graph);
    };
}


#endif //GRAPHPROJECT_EXPORT_H
