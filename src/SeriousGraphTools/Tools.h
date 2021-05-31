#ifndef GRAPHPROJECT_TOOLS_H
#define GRAPHPROJECT_TOOLS_H

#include <algorithm>

namespace SeriousGraphTools {
    class Tools {
    public:
        template<typename T>
        static bool isIn(const T& what, const std::vector<T>& v) {
            return std::find(v.begin(), v.end(), what) != v.end();
        }
    };
}



#endif //GRAPHPROJECT_TOOLS_H
