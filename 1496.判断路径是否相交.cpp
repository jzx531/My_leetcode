/*
 * @lc app=leetcode.cn id=1496 lang=cpp
 *
 * [1496] 判断路径是否相交
 */

// @lc code=start
#include <unordered_set>
#include <functional> // for hash

struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        std::unordered_set<std::pair<int, int>, PairHash> s;
        int x = 0, y = 0;
        s.insert({0, 0});
        for (char c : path) {
            std::pair<int, int> newPos;
            switch(c) {
                case 'N':
                    newPos = std::make_pair(x, ++y);
                    break;
                case 'S':
                    newPos = std::make_pair(x, --y);
                    break;
                case 'E':
                    newPos = std::make_pair(++x, y);
                    break;
                case 'W':
                    newPos = std::make_pair(--x, y);
                    break;
            }
            if (!s.insert(newPos).second) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end