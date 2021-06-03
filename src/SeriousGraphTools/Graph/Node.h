#ifndef GRAPHPROJECT_NODE_H
#define GRAPHPROJECT_NODE_H

#include "../Tools.h"

namespace SeriousGraphTools {
    class Node {

        int id;
        std::vector<Node*> connectedTo;
        std::vector<Node*> connectedFrom;

    public:
        explicit Node(int id) : id(id) {};

        int getId() const {
            return id;
        }

        void setId(int index) {
            Node::id = index;
        }

        /*connect this node to another one
         * return true when successfully connects*/
        bool connectTo(Node* node) {
            if (isConnectedTo(node))
                return false;
            connectedTo.push_back(node);
            return true;
        };

        /*connect to this node from another one
         * return true when successfully connects*/
        bool connectFrom(Node* node) {
            if (isConnectedFrom(node))
                return false;
            connectedFrom.push_back(node);
            return true;
        };

        bool isConnectedTo(const Node* node) const {
            return Tools::isIn(node, connectedTo);
        };

        bool isConnectedFrom(const Node* node) const {
            return Tools::isIn(node, connectedFrom);
        };

        const std::vector<Node *> &getConnectedTo() const {
            return connectedTo;
        }

        const std::vector<Node *> &getConnectedFrom() const {
            return connectedFrom;
        }
    };

}


#endif //GRAPHPROJECT_NODE_H
