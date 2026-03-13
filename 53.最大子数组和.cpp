/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_sum = dp[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};
// @lc code=end

