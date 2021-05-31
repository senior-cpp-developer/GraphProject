#ifndef GRAPHPROJECT_SIMPLEGRAPH_H
#define GRAPHPROJECT_SIMPLEGRAPH_H

#include <vector>
#include "Graph/Node.h"

namespace SeriousGraphTools{
    class SimpleGraph {

        std::vector<Node> nodes;


        SimpleGraph() = default;

    public:
        void addAutoNodes(int hMuch);

    };
}



#endif //GRAPHPROJECT_SIMPLEGRAPH_H
