#ifndef GRAPHPROJECT_SIMPLEGRAPH_H
#define GRAPHPROJECT_SIMPLEGRAPH_H

#include <vector>
#include "Graph/Node.h"
#include "Graph/Edge.h"

namespace SeriousGraphTools{
    class SimpleGraph {

        std::vector<Node> nodes;
        std::vector<Edge> edges;

        bool isDirty = false;
        bool isOriented = false;

    public:
        SimpleGraph() = default;

        void addAutoNodes(int hMuch);

        bool connect (int from, int to, double weight);

        /*Updates graph's stats like isOriented
         * ignores isDirty and forces update*/
        void forceUpdateInfo();

        /*Updates graph's stats like isOriented
         * returns false if there's no need for an update*/
        bool updateInfo();

    private:
        void hasChanged() {isDirty = true;}
        void updateIsOriented();
    };

}



#endif //GRAPHPROJECT_SIMPLEGRAPH_H
