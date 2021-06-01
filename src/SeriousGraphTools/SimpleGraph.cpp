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
        //TODO all to be changed
        std::vector<Node*> from, to;

        for (auto& edge : edges) {
            from.push_back(edge.getFrom());
            to.push_back(edge.getTo());
        }

        Tools::sortDeleteDuplicates(from);
        Tools::sortDeleteDuplicates(to);

        isOriented_ = from.size() != to.size();
    }

    bool SimpleGraph::simplify() {
        bool hasChanged = false;
        for (int i = 0; i < edges.size(); i++)
            for (int j = i + 1; j < edges.size(); j++)
                if (edges[i].getTo() == edges[j].getFrom() && edges[i].getFrom() == edges[j].getTo()
                && edges[i].getWeight() == edges[j].getWeight()) {
                    edges[i].setBi(true);
                    edges.erase(edges.begin() + j);
                    hasChanged = true;
                }
        if (hasChanged) this->hasChanged();
        return hasChanged;
    }
}
