/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        int i = 0;
        int count = 0;
        int n = nums.size();
        while(i < n)
        {
            count = 0;
            while(i < n - 1 && nums[i] == nums[i+1])
            {
                count++;
                i++;
            }
            if(count == 0){
                tmp.push_back(nums[i]);
            }
            i++;
        }
        return accumulate(tmp.begin(), tmp.end(), 0);
    }
};
// @lc code=end

