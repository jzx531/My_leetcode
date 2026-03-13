/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int targetSum, int curSum, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;
        curSum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && curSum == targetSum) {
            res.push_back(path);
        }
        dfs(root->left, targetSum, curSum, path, res);
        dfs(root->right, targetSum, curSum, path, res);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, 0, path, res);
        return res;
    }
};
// @lc code=end

