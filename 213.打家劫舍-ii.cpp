/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        // if(nums.size()<=2) return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        dp[0][0] = nums[0];
        dp[0][1] = 0; 
        dp[1][0] = nums[0];
        dp[1][1] = nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            if(i == nums.size()-1)
            {
                dp[i][0]=dp[i-1][0];
            }
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-2][0]+nums[i]);
            }
            dp[i][1]=max(dp[i-1][1],dp[i-2][1]+nums[i]);
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};
// @lc code=end

