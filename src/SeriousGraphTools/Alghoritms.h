#ifndef GRAPHPROJECT_ALGHORITMS_H
#define GRAPHPROJECT_ALGHORITMS_H

#include "SimpleGraph.h"

namespace SeriousGraphTools {
    class Alghoritms {
    public:
        static double edmondsKarp(const SimpleGraph& graph, int inId, int outId);
    };
}



#endif //GRAPHPROJECT_ALGHORITMS_H
