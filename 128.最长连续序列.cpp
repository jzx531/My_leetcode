/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int res = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] == nums[i-1]+1) {
                cnt++;
            } else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        return max(res, cnt);
    }
};
// @lc code=end

