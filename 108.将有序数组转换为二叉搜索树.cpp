/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode*  insert(TreeNode* &root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
    TreeNode * sortedArrayToBST(vector<int>& nums,int left,int right)
    {
        if(left >= right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    } 
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = sortedArrayToBST(nums, 0, nums.size());
        return root;
    }
};
// @lc code=end

