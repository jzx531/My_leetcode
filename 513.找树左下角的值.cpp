/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    void inorder(TreeNode* root, int& res, int& level, int cur_level)
    {
        if(root == nullptr) return ;
        if(cur_level > level){
            res = root->val;
            level = cur_level;
        }
        inorder(root->left, res, level, cur_level+1);
        inorder(root->right, res, level, cur_level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int res = 0, level = 0, cur_level = 0;
        res = root->val;
        inorder(root, res, level, cur_level);
        return res;
    }
};
// @lc code=end

