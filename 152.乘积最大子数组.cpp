/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n,0);
    //     dp[0] = nums[0];
    //     int max_product = nums[0];
    //     for(int i = 1;i<n;++i)
    //     {
    //         dp[i] = nums[i];
    //         int tmp = dp[i];
    //         if(i>0 &&dp[i-1]>0&&nums[i]>0)
    //         {
    //             dp[i] = dp[i-1]*nums[i];
    //             max_product = max(max_product,dp[i]);
    //             continue;   
    //         }
    //         for(int j = i-1;j>=0;--j)
    //         {
    //             tmp = tmp*nums[j];
    //             dp[i] = max(dp[i],tmp);
    //         }
    //         max_product = max(max_product,dp[i]);
    //     }
    //     return max_product;
    // }
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            // If current number is negative, swapping max and min will give correct products
            if (nums[i] < 0) {
                swap(max_prod, min_prod);
            }
            
            // Update max and min products for current position
            max_prod = max(nums[i], max_prod * nums[i]);
            min_prod = min(nums[i], min_prod * nums[i]);
            
            // Update overall result
            result = max(result, max_prod);
        }
        
        return result;
    }
};
// @lc code=end

