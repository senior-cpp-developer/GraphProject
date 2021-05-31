#include "SimpleGraph.h"
namespace SeriousGraphTools {
    void SimpleGraph::addAutoNodes(int hMuch) {
        hasChanged();
        int start = nodes.size();
        for (int i = start; i < hMuch + start; i++)
            nodes.emplace_back(i);
    }

    bool SimpleGraph::connect(int from, int to, double weight) {
        hasChanged();
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

    bool SimpleGraph::updateInfo() {
        if (isDirty_) {
            forceUpdateInfo();
            return true;
        }
        else
            return false;
    }

    void SimpleGraph::forceUpdateInfo() {
        isDirty_ = false;
        updateIsOriented();
    }

    void SimpleGraph::updateIsOriented() {
        std::vector<Node*> from, to;

        for (auto& edge : edges) {
            from.push_back(edge.getFrom());
            to.push_back(edge.getTo());
        }

        Tools::sortDeleteDuplicates(from);
        Tools::sortDeleteDuplicates(to);

        isOriented_ = from.size() != to.size();
    }
}
