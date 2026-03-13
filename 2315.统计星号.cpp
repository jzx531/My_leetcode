/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool inside = false; // 标记是否在一对竖线之间
        for (char c : s) {
            if (c == '|') {
                inside = !inside; // 遇到竖线切换状态
            } else if (c == '*' && !inside) {
                count++; // 不在竖线对之间的 '*' 才计数
            }
        }
        return count;
    }
};
// @lc code=end

