/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    void dfs(TreeNode* root,int&sum,int low,int high)
    {
        if(!root) return;
        if(root->val>=low) dfs(root->left,sum,low,high);
        if(root->val<=high) dfs(root->right,sum,low,high);
        if(root->val>=low && root->val<=high) sum+=root->val;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        dfs(root,sum,low,high);
        return sum;
    }
};
// @lc code=end

