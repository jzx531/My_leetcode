/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root,TreeNode *&target,TreeNode *p,TreeNode *q)
    {
        if(!root) return;
        if(p->val<=root->val && q->val>=root->val) {target=root;return;}
        // if(p->val>root->val) dfs(root->right,target,p,q);
        // if(q->val<root->val) dfs(root->left,target,p,q);
        dfs(root->left,target,p,q);
        dfs(root->right,target,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* target=nullptr;
        if(p->val>q->val) swap(p,q);
        dfs(root,target,p,q);
        return target;
    }
};
// @lc code=end

