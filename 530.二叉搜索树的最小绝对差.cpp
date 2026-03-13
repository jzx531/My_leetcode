/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void inorder(TreeNode* root, TreeNode*& prev, int& min_diff) {
        if (!root) return;
        inorder(root->left, prev, min_diff);
        if (prev) {
            min_diff = min(min_diff, root->val - prev->val); // 因为是 BST，中序遍历是升序，所以直接相减即可
        }
        prev = root;
        inorder(root->right, prev, min_diff);
    }

    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, min_diff);
        return min_diff;
    }
};
// @lc code=end

