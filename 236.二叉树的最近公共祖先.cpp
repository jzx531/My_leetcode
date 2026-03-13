/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    void dfs(TreeNode*root,TreeNode*p,vector<TreeNode*>&path)
    {
        if(!root) return;
        path.push_back(root);
        if(root==p) return;
        if(root->left) dfs(root->left,p,path);
        if(root->right) dfs(root->right,p,path);
        if(path.back()==p) return;
        path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        dfs(root,p,path1);
        dfs(root,q,path2);
        int n=min(path1.size(),path2.size());
        for(int i=0;i<n;i++)
        {
            if(path1[i]!=path2[i]) return path1[i-1];
        }
        return path1[n-1];
    }
};
// @lc code=end

