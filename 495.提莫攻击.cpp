/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            res += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return res + duration;
    }
};
// @lc code=end

