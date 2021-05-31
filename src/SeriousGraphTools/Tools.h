#ifndef GRAPHPROJECT_TOOLS_H
#define GRAPHPROJECT_TOOLS_H

namespace SeriousGraphTools {
    class Tools {
        template<typename T>
        static bool isIn(const std::vector<T>& v, const T& what) {
            return std::find(v.begin(), v.end(), what) != v.end();
        }
    };
}



#endif //GRAPHPROJECT_TOOLS_H
