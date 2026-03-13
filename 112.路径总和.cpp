/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    void dfs(TreeNode* root, int targetSum, int sum, bool& res){
        if(!root) return;
        sum += root->val;
        if(!root->left &&!root->right && sum == targetSum) res = true;
        dfs(root->left, targetSum, sum, res);
        dfs(root->right, targetSum, sum, res);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        bool res = false;
        dfs(root, targetSum, 0, res);
        return res;
    }
};
// @lc code=end

