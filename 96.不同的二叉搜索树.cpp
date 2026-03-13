/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
// vector<TreeNode*> generateTrees(int n) {
//     if (n == 0) return {};
//     return generateTrees(1, n);
// }

// vector<TreeNode*> generateTrees(int start, int end) {
//     vector<TreeNode*> res;
//     if (start > end) {
//         res.push_back(nullptr);
//         return res;
//     }
//     for (int i = start; i <= end; i++) {
//         vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
//         vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
//         for (TreeNode* left : leftTrees) {
//             for (TreeNode* right : rightTrees) {
//                 TreeNode* root = new TreeNode(i, left, right);
//                 res.push_back(root);
//             }
//         }
//     }
//     return res;
// }
//     int numTrees(int n) {
//         vector<TreeNode*> trees = generateTrees(n);
//         return trees.size();
//     }
       int numTrees(int n) {
        if (n == 0) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;  
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

