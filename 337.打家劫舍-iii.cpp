/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
pair<int, int> dfs(TreeNode* node) {
    if (!node) {
        return {0, 0};
    }
    auto left = dfs(node->left);
    auto right = dfs(node->right);
    // dp[0]: 不偷当前节点，可以偷左右子节点
    int not_rob = max(left.first, left.second) + max(right.first, right.second);
    // dp[1]: 偷当前节点，不能偷左右子节点
    int rob = node->val + left.first + right.first;
    return {not_rob, rob};
}
int rob(TreeNode* root) {
    auto result = dfs(root);
    return max(result.first, result.second);
}

};
// @lc code=end

