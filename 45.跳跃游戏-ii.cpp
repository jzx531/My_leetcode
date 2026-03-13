/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    
    // int jump(vector<int>& nums) {
    //     vector<int> dp(nums.size(),INT_MAX);
    //     dp[0] = 0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         for(int j=1;j<=nums[i] && j+i<nums.size();j++)
    //         {
    //             dp[i+j] = min(dp[i+j],dp[i]+1);
    //         }
    //     }
    //     return dp[nums.size()-1];
    // }
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
// @lc code=end

