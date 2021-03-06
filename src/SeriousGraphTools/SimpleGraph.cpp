#include "SimpleGraph.h"
#include <stdexcept>
namespace SeriousGraphTools {
    void SimpleGraph::addAutoNodes(int hMuch) {
        hasChanged();
        int start = nodes.size();
        for (int i = start; i < hMuch + start; i++)
            nodes.emplace_back(i);
    }

    bool SimpleGraph::connect(int from, int to, double weight, bool isBi) {
        hasChanged();
        bool isNew = true;
        nodes[from].connectTo(&nodes[to]) ? : isNew = false;
        nodes[to].connectFrom(&nodes[from]) ? : isNew = false;
        if (isBi) {
            nodes[from].connectFrom(&nodes[to]) ? : isNew = false;
            nodes[to].connectTo(&nodes[from]) ? : isNew = false;
        }

        if (isNew)
        {
            edges.emplace_back(&nodes[from], &nodes[to], weight, isBi);
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

    const Edge& SimpleGraph::getEdge(const Node* from, const Node* to) const {
        for (auto& edge : edges)
            if (edge.getFrom() == from && edge.getTo() == to)
                return edge;
        throw std::invalid_argument("Edge not found");
    }

    Edge &SimpleGraph::edge(int from, int to) {
        return const_cast<Edge &>(getEdge(&nodes[from], &nodes[to])); //good enough
    }

    Edge &SimpleGraph::edge(const Node *from, const Node *to) {
        return edge(from, to);
    }

    const Edge &SimpleGraph::getEdge(int from, int to) const {
        return getEdge(&nodes[from], &nodes[to]);
    }
}
