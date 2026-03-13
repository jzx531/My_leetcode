/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    void zigzagLevelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (level == res.size()) res.push_back({});
        if (level % 2 == 0) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);
        zigzagLevelOrder(root->left, level + 1, res);
        zigzagLevelOrder(root->right, level + 1, res);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagLevelOrder(root, 0, res);
        return res;
    }
};
// @lc code=end

