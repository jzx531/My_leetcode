/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    void dfs(TreeNode* root, bool& isUnival,int val)
    {
        if (!root) return;
        if(root->val!= val) {isUnival = false;
            return;
        }
        dfs(root->left, isUnival, val);
        dfs(root->right, isUnival, val);
    }
    bool isUnivalTree(TreeNode* root) {
        bool res = true;
        dfs(root, res, root->val);
        return res;
    }
};
// @lc code=end

