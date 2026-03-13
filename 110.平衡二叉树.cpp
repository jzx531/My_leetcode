/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    void dfs(TreeNode* root, int h,int& height){
        if(!root) return;
        if(h > height) height = h;
        dfs(root->left, h+1, height);
        dfs(root->right, h+1, height);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh = 0, rh = 0;
        dfs(root->left, 1, lh);
        dfs(root->right, 1, rh);
        return abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end

