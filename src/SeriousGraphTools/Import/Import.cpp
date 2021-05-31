#include "Import.h"

namespace SeriousGraphTools {
    SimpleGraph Import::importFromAdjacencyList(const json &json) {

        SimpleGraph graph;
        graph.addAutoNodes(json.size());

        return graph;
    }
}
