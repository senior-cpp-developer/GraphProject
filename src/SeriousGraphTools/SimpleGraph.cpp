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
        if (!nodes[from].isConnectedTo(&nodes[to])
        && !nodes[to].isConnectedFrom(&nodes[from])){
            edges.emplace_back(&nodes[from], &nodes[to], weight);
            nodes[from].addConnection(&edges[edges.size() - 1]);
            nodes[to].addConnection(&edges[edges.size() - 1]);
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
        for (auto& edge : edges)
            if (!edge.isBi())
            {
                isOriented_ = true;
                return;
            }
        isOriented_ = false;
    }

    bool SimpleGraph::simplify() {
        bool hasChanged = false;
        for (int i = 0; i < edges.size(); i++)
            for (int j = i + 1; j < edges.size(); j++)
                if (edges[i].getTo() == edges[j].getFrom() && edges[i].getFrom() == edges[j].getTo()
                && edges[i].getWeight() == edges[j].getWeight()) {
                    edges[i].setBi(true);
                    edges[j].getFrom()->deleteConnection(&edges[j]);
                    edges[j].getTo()->deleteConnection(&edges[j]);
                    edges.erase(edges.begin() + j);
                    hasChanged = true;
                }
        if (hasChanged) this->hasChanged();
        return hasChanged;
    }
}
