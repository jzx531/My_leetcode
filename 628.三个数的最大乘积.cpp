/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long res1=INT_MIN, res2=INT_MIN;
        int n=nums.size();
        res1 = nums[0] * nums[1] * nums[n-1];
        res2 = nums[n-1] * nums[n-2] * nums[n-3];
        return max(res1, res2);
    }
};
// @lc code=end

