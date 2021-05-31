#include "Import.h"

namespace SeriousGraphTools {
    SimpleGraph Import::importFromAdjacencyList(const json &json) {

        SimpleGraph graph;
        graph.addAutoNodes(json.size());

        for(int i = 0; i < json.size(); i++)
            for (auto& val : json[i])
                graph.connect(i, val, 1);

        return graph;
    }
}
