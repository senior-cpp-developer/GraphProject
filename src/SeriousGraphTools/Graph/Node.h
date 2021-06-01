#ifndef GRAPHPROJECT_NODE_H
#define GRAPHPROJECT_NODE_H

#include "../Tools.h"
#include "Edge.h"

namespace SeriousGraphTools {
    class Node {

        int id;
        std::vector<Edge*> connectionsTo;
        std::vector<Edge*> connectionsFrom;
        std::vector<Edge*> connections;

    public:
        explicit Node(int id) : id(id) {};

        int getId() const {
            return id;
        }

        void setId(int index) {
            Node::id = index;
        }

        /*adds connection to/from this node
         * returns true if successful */
        bool addConnection(Edge* const edge) {
            if (isConnected(edge))
                return false;
            if (edge->getTo() == this)
                connectionsTo.push_back(edge);
            else if (edge->getFrom() == this)
                connectionsFrom.push_back(edge);
            else
                return false;
            return true;
        };

        bool isConnected(Edge* const edge) const {
            return Tools::isIn(edge, connectionsTo) || Tools::isIn(edge, connectionsFrom);
        }

        bool isConnectedFrom(Node* node) const {
            for (auto& edge : connectionsTo)
                if (edge->getFrom() == node)
                    return true;
            return false;
        }

        bool isConnectedTo(Node* node) const {
            for (auto& edge : connectionsFrom)
                if (edge->getTo() == node)
                    return true;
            return false;
        }
    };

}


#endif //GRAPHPROJECT_NODE_H
