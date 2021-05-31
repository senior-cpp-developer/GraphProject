#ifndef GRAPHPROJECT_SIMPLEGRAPH_H
#define GRAPHPROJECT_SIMPLEGRAPH_H

#include <vector>
#include "Graph/Node.h"
#include "Graph/Edge.h"

namespace SeriousGraphTools{
    class SimpleGraph {

        std::vector<Node> nodes;
        std::vector<Edge> edges;

    public:
        SimpleGraph() = default;

        void addAutoNodes(int hMuch);

        bool connect (int from, int to, double weight);

    };

}



#endif //GRAPHPROJECT_SIMPLEGRAPH_H
