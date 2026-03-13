/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm, vector<int>& visited) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) {
                continue;
            }
            visited[i] = 1;
            perm.push_back(nums[i]);
            backtrack(nums, res, perm, visited);
            visited[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end());  // 必须先排序才能有效去重
        backtrack(nums, res, perm, visited);
        return res;
    }
};
// @lc code=end

