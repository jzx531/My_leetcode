/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                int j=i+1;
                while(j<nums.size()&&nums[j]==1){
                    j++;
                }
                max_ones=max(max_ones,j-i);
                i=j-1;
            }
        }
        return max_ones;
    }
};
// @lc code=end

