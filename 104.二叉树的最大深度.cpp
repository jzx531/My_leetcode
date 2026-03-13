/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    void dfs(TreeNode* root, int h,int& maxheight)
    {
        if (!root) return;
        if (h > maxheight) maxheight = h;
        dfs(root->left, h + 1, maxheight);
        dfs(root->right, h + 1, maxheight);
    }
    
    int maxDepth(TreeNode* root) {
        int res = 0;
        dfs(root, 1, res);
        return res;
    }
};
// @lc code=end

