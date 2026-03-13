/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            backtrack(nums, 0, res);
            return res;
        }
        
        void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
            if (start == nums.size()) {
                res.push_back(nums);
                return;
            }
            
            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);      // 交换当前元素与起始元素
                backtrack(nums, start + 1, res); // 递归处理剩余元素
                swap(nums[start], nums[i]);      // 回溯，恢复原始状态
            }
        }
    
};
// @lc code=end

