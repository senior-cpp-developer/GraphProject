#ifndef GRAPHPROJECT_TOOLS_H
#define GRAPHPROJECT_TOOLS_H

#include <algorithm>

namespace SeriousGraphTools {
    class Tools {
    public:
        /*checks if exist*/
        template<typename T>
        static bool isIn(const T& what, const std::vector<T>& v) {
            return std::find(v.begin(), v.end(), what) != v.end();
        }

        template<typename T>
        static void sortDeleteDuplicates(std::vector<T>& v) {
            std::sort(v.begin(), v.end());
            auto iter = std::unique(v.begin(), v.end());
            v.erase(iter, v.end());
        }

        /*removes by value*/
        template<typename T>
        static void eraseRemove(const T& what, std::vector<T>& v) {
            v.erase(std::remove(v.begin(), v.end(), what), v.end());
        }
    };
}



#endif //GRAPHPROJECT_TOOLS_H
