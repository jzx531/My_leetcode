/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    void dfs(TreeNode* root, int depth, int& min_depth) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            min_depth = min(min_depth, depth);
            return;
        }
        dfs(root->left, depth + 1, min_depth);
        dfs(root->right, depth + 1, min_depth);
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int min_depth = INT_MAX;
        dfs(root, 1, min_depth);
        return min_depth;
    }
};
// @lc code=end

