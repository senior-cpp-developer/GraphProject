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
                    edges.erase(edges.begin() + j);
                    hasChanged = true;
                }
        if (hasChanged) this->hasChanged();
        return hasChanged;
    }

    const Edge& SimpleGraph::getEdge(Node *const from, Node *const to) const {
        for (auto& edge : edges)
            if (edge.getFrom() == from && edge.getTo() == to)
                return edge;
    }
}
