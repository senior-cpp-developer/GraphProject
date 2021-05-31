#ifndef GRAPHPROJECT_SIMPLEGRAPH_H
#define GRAPHPROJECT_SIMPLEGRAPH_H

#include <vector>
#include "Graph/Node.h"
#include "Graph/Edge.h"

namespace SeriousGraphTools{
    template <typename WEIGHT>
    class SimpleGraph {

        std::vector<Node> nodes;
        std::vector<Edge<WEIGHT>> edges;

    public:
        SimpleGraph() = default;

        void addAutoNodes(int hMuch);

        bool connect (int from, int to);

    };

}



#endif //GRAPHPROJECT_SIMPLEGRAPH_H
