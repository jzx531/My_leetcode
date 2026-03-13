/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 2) return 0;
        int max_gap = 0;
        for (int i = 1; i < n; i++) {
            max_gap = max(max_gap, nums[i] - nums[i - 1]);
        }
        return max_gap;
    }
};
// @lc code=end

