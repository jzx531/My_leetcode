/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    void copyNode(TreeNode* src, TreeNode*& dest)
    {
        if (src == nullptr)
        {
            dest = nullptr;
            return;
        }
        dest = new TreeNode(src->val);
        copyNode(src->left, dest->right);
        copyNode(src->right, dest->left);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode * res;
        copyNode(root, res);
        return res;
    }
};
// @lc code=end

