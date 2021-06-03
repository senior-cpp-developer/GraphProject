#ifndef GRAPHPROJECT_EDGE_H
#define GRAPHPROJECT_EDGE_H

#include "Node.h"

namespace SeriousGraphTools {
    class Edge {
        Node* from;
        Node* to;
        double weight;
        bool isBi_;

    public:
        Edge(Node* from, Node* to, double weight, bool isBi)
            : from(from), to(to), weight(weight), isBi_(isBi) {};

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

        double getWeight() const {
            return weight;
        }

        void setWeight(double weight) {
            Edge::weight = weight;
        }

        bool isBi() const {
            return isBi_;
        }

        void setBi(bool isBi) {
            isBi_ = isBi;
        }
    };
}

#endif //GRAPHPROJECT_EDGE_H
