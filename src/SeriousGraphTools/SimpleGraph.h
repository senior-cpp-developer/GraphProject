#ifndef GRAPHPROJECT_SIMPLEGRAPH_H
#define GRAPHPROJECT_SIMPLEGRAPH_H

#include <vector>
#include "Graph/Node.h"
#include "Graph/Edge.h"

namespace SeriousGraphTools{
    class SimpleGraph {

        std::vector<Node> nodes;
        std::vector<Edge> edges;

        bool isDirty_ = false;
        bool isOriented_ = false;

    public:
        SimpleGraph() = default;

        void addAutoNodes(int hMuch);

        bool connect (int from, int to, double weight);

        /*Updates graph's stats like isOriented_
         * ignores isDirty_ and forces update*/
        void forceUpdateInfo();

        /*Updates graph's stats like isOriented_
         * returns false if there's no need for an update*/
        bool updateInfo();

        bool isOriented() {updateInfo(); return isOriented_;};

        const std::vector<Node> &getNodes() const {return nodes;}

        const std::vector<Edge> &getEdges() const {return edges;}

    private:
        void hasChanged() { isDirty_ = true;}
        void updateIsOriented();
    };

}



#endif //GRAPHPROJECT_SIMPLEGRAPH_H
