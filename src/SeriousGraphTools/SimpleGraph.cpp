#include "SimpleGraph.h"
namespace SeriousGraphTools {
    void SimpleGraph::addAutoNodes(int hMuch) {
        int start = nodes.size();
        for (int i = start; i < hMuch + start; i++)
            nodes.emplace_back(i);
    }

    bool SimpleGraph::connect(int from, int to, double weight) {
        bool isNew = true;
        nodes[from].connectTo(&nodes[to]) ? : isNew = false;
        nodes[to].connectFrom(&nodes[from]) ? : isNew = false;

        if (isNew)
        {
            edges.emplace_back(&nodes[from], &nodes[to], weight);
            return true;
        }
        else
            return false;

    }
}
