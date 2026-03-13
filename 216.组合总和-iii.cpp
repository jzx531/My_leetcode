/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res) {
        if(temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == n){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(i+1, k, n, nums, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        backtrack(0, k, n, nums, temp, res);
        return res;
    }
};
// @lc code=end

