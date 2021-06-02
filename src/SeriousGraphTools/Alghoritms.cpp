#include "Alghoritms.h"
#include <limits>
#include <queue>

namespace SeriousGraphTools {
    double Alghoritms::edmondsKarp(const SimpleGraph &graph, int inId, int outId) {
        int n = graph.hManyNodes();
        SimpleGraph flowsGraph;
        flowsGraph.addAutoNodes(n);
        for (auto& edge : graph.getEdges())
        {
            flowsGraph.connect(edge.getFrom()->getId(), edge.getTo()->getId(), 0, false);
//            if (edge.isBi())
                flowsGraph.connect(edge.getTo()->getId(), edge.getFrom()->getId(), 0, false);
        }


        double fmax = 0;
        std::vector<double> cfp;
        for (int i = 0; i < n; i++) cfp.push_back(0);

        while(true) {
            std::vector<int> previouses;
            previouses.reserve(n);
            for (int i = 0; i < n; i++) previouses.push_back(-1);

            previouses[inId] = -2;

            cfp[inId] = std::numeric_limits<int>::max();

            std::queue<int> queue;
            queue.push(inId);

            bool esc = false;

            while (!queue.empty()) {
                int x = queue.front();
                const Node* nodeX = &graph.getNodes()[x];
                queue.pop();

                for (auto& nodeY : graph.getNodes()[x].getConnectedTo()) {
                    int y = nodeY->getId();
                    double cp = graph.getEdge(x, y).getWeight()
                            - flowsGraph.getEdge(x, y).getWeight();
                    if (cp != 0 && previouses[y] == -1) {
                        previouses[y] = x;

                        cfp[y] = cfp[x] > cp ? cp : cfp[x];

                        if (y == outId) {
                            fmax += cfp[outId];

                            int i = y;
                            while (i != inId) {
                                x = previouses[i];
                                flowsGraph.edge(x, i).setWeight(flowsGraph.edge(x, i).getWeight() + cfp[outId]);
                                flowsGraph.edge(i, x).setWeight(flowsGraph.edge(i, x).getWeight() - cfp[outId]);
                                i = x;
                            }

                            esc = true;
                            break;
                        }
                        queue.push(y);
                    }
                }
                if (esc)
                    break;
            }
            if (!esc)
                break;
        }

        return fmax;
    }
}

