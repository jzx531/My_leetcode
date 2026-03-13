/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
void dfs(TreeNode* root, int x, int h, int& height, TreeNode* p, TreeNode*& parent) {
    if (!root || parent != nullptr) {
        return;
    }
    if (root->val == x) {
        height = h;
        parent = p;
        return;
    }
    dfs(root->left, x, h + 1, height, root, parent);
    dfs(root->right, x, h + 1, height, root, parent);
}

bool isCousins(TreeNode* root, int x, int y) {
    int xHeight = 0, yHeight = 0;
    TreeNode *xParent = nullptr, *yParent = nullptr;
    dfs(root, x, 0, xHeight, nullptr, xParent);
    dfs(root, y, 0, yHeight, nullptr, yParent);
    return xHeight == yHeight && xParent != yParent;
}
};
// @lc code=end

