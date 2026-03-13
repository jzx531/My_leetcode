/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    void dfs(TreeNode* root, int& sum,bool is_left)
    {
        if (!root) return;
        if (!root->left && !root->right && is_left) sum += root->val;
        dfs(root->left, sum, true);
        dfs(root->right, sum, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        int sum = 0;
        dfs(root, sum, true);
        return sum;
    }
};
// @lc code=end

