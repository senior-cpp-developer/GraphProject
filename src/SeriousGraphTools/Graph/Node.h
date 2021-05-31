#ifndef GRAPHPROJECT_NODE_H
#define GRAPHPROJECT_NODE_H

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
        bool connectTo(Node* const node);

        /*connect to this node from another one
         * return true when successfully connects*/
        bool connectFrom(Node* const node);

        bool isConnectedTo(Node* const node) const;

        bool isConnectedFrom(Node* const node) const;
    };

}


#endif //GRAPHPROJECT_NODE_H
