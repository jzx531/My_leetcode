/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //     vector<bool> dp(nums.size(), false);
    //     dp[0]=true;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(dp[i])
    //         {
    //             for(int j=1;j<=nums[i] && j+i<nums.size();j++)
    //             {
    //                 dp[i+j] = true;
    //             }
    //         }
    //     }
    //     return dp[nums.size()-1];
    // }
    // bool canJump(vector<int>& nums) {
    //     vector<int> dp(nums.size(), INT_MAX-nums.size());
    //     dp[0] = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j <= nums[i] && j + i < nums.size(); j++) {
    //             dp[i + j] = min(dp[i + j], dp[i] + 1);
    //         }
    //     }
    //     return dp[nums.size() - 1] <= nums.size() - 1;
    // }
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // Can't reach this index
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

