/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    void inorder(TreeNode* root, TreeNode *&prev,bool &flag) {
        if (root == nullptr) return;
        if(!flag) return;
        inorder(root->left, prev, flag);
        if (prev!= nullptr && prev->val >= root->val) {
            flag = false;
            return;
        }
        prev = root;
        inorder(root->right, prev, flag);
    }

    bool isValidBST(TreeNode* root) {
        bool flag = true;
        TreeNode *prev = nullptr;
        inorder(root, prev, flag);
        return flag;
    }
};
// @lc code=end

