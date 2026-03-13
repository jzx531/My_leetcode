/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void backtrack(int start, int k, int n, vector<vector<int>>& res, vector<int>& tmp) {
        if(tmp.size() == k) res.push_back(tmp);
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            backtrack(i+1, k, n, res, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> res;

        backtrack(1, k, n, res, tmp);
        return res;
    }
};
// @lc code=end

