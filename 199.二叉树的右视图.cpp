/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    void rightSideView(TreeNode* root, int level, int& max_level, vector<int>& res) {
        if (root == nullptr) return;
        if (level > max_level) {
            res.push_back(root->val);
            max_level = level;
        }
        rightSideView(root->right, level + 1, max_level, res);
        rightSideView(root->left, level + 1, max_level, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int max_level = 0;
        rightSideView(root, 1, max_level, res);
        return res;
    }
};
// @lc code=end

