#include "Alghoritms.h"
#include <limits>
#include <queue>

namespace SeriousGraphTools {
    double Alghoritms::edmondsKarp(const SimpleGraph &graph, int inId, int outId) {
        int n = graph.hManyNodes();
        SimpleGraph flowsGraph;
        flowsGraph.addAutoNodes(n);

        double fmax = 0;
        std::vector<double> cfp;
        for (int i = 0; i < n; i++) cfp.push_back(0);

        while(true) {
            std::vector<int> previouses;
            for (int i = 0; i < n; i++) previouses.push_back(0);

            previouses[inId] = -2;

            cfp[inId] = std::numeric_limits<int>::max();

            std::queue<int> queue;
            queue.push(inId);

            bool esc = false;

            while (!queue.empty()) {
                int x = queue.front();
                const Node* nodeX = &graph.getNodes()[x];
                queue.pop();

                for (auto nodeY : graph.getNodes()[x].getConnectedTo()) {
                    double cp = graph.getEdge(nodeX, &nodeY);
                }
            }
        }
    }
}

