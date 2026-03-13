/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        int i = 0 ;
        while(i<n-2){
            if(nums[i]!=nums[i+1] && nums[i]!=nums[i+2]){
                return nums[i];
            }
            i+=3;
        }
        return nums[n-1];
    }
};
// @lc code=end

