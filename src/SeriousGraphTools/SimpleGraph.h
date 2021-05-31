#ifndef GRAPHPROJECT_SIMPLEGRAPH_H
#define GRAPHPROJECT_SIMPLEGRAPH_H

#include <vector>
#include "Graph/Node.h"
#include "Graph/Edge.h"

namespace SeriousGraphTools{
    template <typename T>
    class SimpleGraph {

        std::vector<Node> nodes;
        std::vector<Edge<T>> connections;


        SimpleGraph() = default;

    public:
        void addAutoNodes(int hMuch);

    };
}



#endif //GRAPHPROJECT_SIMPLEGRAPH_H
