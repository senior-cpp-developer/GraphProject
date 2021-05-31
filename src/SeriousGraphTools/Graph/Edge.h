#ifndef GRAPHPROJECT_EDGE_H
#define GRAPHPROJECT_EDGE_H

#include "Node.h"

namespace SeriousGraphTools {
    template <typename T>
    class Edge {
        Node* from;
        Node* to;
        T weight;

    public:
        Edge(Node* const from, Node* const to, T weight)
            : from(from), to(to), weight(weight) {};

        Node *getFrom() const {
            return from;
        }

        void setFrom(Node *from) {
            Edge::from = from;
        }

        Node *getTo() const {
            return to;
        }

        void setTo(Node *to) {
            Edge::to = to;
        }

        T getWeight() const {
            return weight;
        }

        void setWeight(T weight) {
            Edge::weight = weight;
        }
    };
}

#endif //GRAPHPROJECT_EDGE_H
