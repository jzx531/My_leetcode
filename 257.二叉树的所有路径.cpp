/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if(root->left == nullptr && root->right == nullptr){
            res.push_back(path + "->" + to_string(root->val));
            return;
        }
        if(root->left) dfs(root->left, path + "->" + to_string(root->val), res);
        if(root->right) dfs(root->right, path + "->" + to_string(root->val), res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> res;
        if(root == nullptr) return res;
        if(root->left == nullptr && root->right == nullptr){
            res.push_back(to_string(root->val));
            return res;
        }
        path = to_string(root->val);
        if(root->left) dfs(root->left, path, res);
        if(root->right) dfs(root->right, path , res);
        return res;
    }
};
// @lc code=end

