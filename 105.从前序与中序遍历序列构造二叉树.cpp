/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()|| preorder.size()!= inorder.size()) {
            return nullptr;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }
        int root_val = preorder[pre_start];
        int index = find(inorder.begin() + in_start, inorder.begin() + in_end + 1, root_val) - inorder.begin();
        int left_size = index - in_start;
        TreeNode* root = new TreeNode(root_val);
        root->left = buildTree(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, index - 1);
        root->right = buildTree(preorder, pre_start + left_size + 1, pre_end, inorder, index + 1, in_end);
        return root;
    }
};
// @lc code=end

