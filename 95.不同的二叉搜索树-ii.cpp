/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
//     TreeNode* insert(TreeNode* &root, int val) {
//         if (!root) {
//             root = new TreeNode(val);
//             return root;
//         }
//         if (val < root->val) {
//             root->left = insert(root->left, val);
//         } else {
//             root->right = insert(root->right, val);
//         }
//         return root;
//     }

// TreeNode * buildTree(vector<int>& nums) {
//      TreeNode* root = nullptr;
//         for (int i = 0; i < nums.size(); i++) {
//             insert(root, nums[i]);
//         }
//         return root;
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         backtrack(nums, 0, res);
//         return res;
//     }
    
//     void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
//         if (start == nums.size()) {
//             res.push_back(nums);
//             return;
//         }
        
//         for (int i = start; i < nums.size(); i++) {
//             swap(nums[start], nums[i]);      // 交换当前元素与起始元素
//             backtrack(nums, start + 1, res); // 递归处理剩余元素
//             swap(nums[start], nums[i]);      // 回溯，恢复原始状态
//         }
//     }
    
//     vector<TreeNode*> generateTrees(int n) {
//         if(n == 0) return vector<TreeNode*>();
//         vector<vector<int>> tmp;
//         vector<int> nums;
//         for(int i = 1; i <= n; i++) {
//             nums.push_back(i);
//         }
//         tmp = permute(nums);
//         vector<TreeNode*> res;
//         for(int i = 0; i < tmp.size(); i++) {
//             TreeNode* root = buildTree(tmp[i]);
//             res.push_back(root);
//         }
//         return res;
//     }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

