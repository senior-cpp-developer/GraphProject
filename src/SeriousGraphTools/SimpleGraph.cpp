#include "SimpleGraph.h"
namespace SeriousGraphTools {
    template<typename WEIGHT>
    void SimpleGraph<WEIGHT>::addAutoNodes(int hMuch) {
        int start = nodes.size();
        for (int i = start; i < hMuch + start; i++)
            nodes.emplace_back(start);
    }

    template<typename WEIGHT>
    bool SimpleGraph<WEIGHT>::connect(int from, int to) {
        bool isNew = true;
        nodes[from].connectTo(&nodes[to]) ? : isNew = false;
        nodes[to].connectFrom(&nodes[from]) ? : isNew = false;

        if (isNew)
        {
            edges.emplace_back(&nodes[from], &nodes[to]);
            return true;
        }
        else
            return false;

    }
}
