/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[n-1];
    }
};
// @lc code=end

