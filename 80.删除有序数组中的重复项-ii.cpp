/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = nums.begin();
        if(nums.size() < 3) return nums.size();
        while (it!= nums.end()-2) {
            if(*it == *(it+1) && *(it+1) == *(it+2))
            {
                it = nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
};
// @lc code=end

