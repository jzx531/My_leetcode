/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    void calculateLevel(TreeNode* root, int level,vector<int>& levelCount,vector<double>& res) {
        if (root == nullptr) {
            return;
        }
        if(level >=levelCount.size()){
            levelCount.push_back(1);
            res.push_back((double)root->val);
        }
        else{
            levelCount[level]++;
            res[level] += (double)root->val;
        }
        calculateLevel(root->left, level+1, levelCount, res);
        calculateLevel(root->right, level+1, levelCount, res);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)return {};
        vector<int> levelCount;
        vector<double> res;
        calculateLevel(root, 0, levelCount, res);
        for(int i=0;i<res.size();i++){
            res[i] /= levelCount[i];
        }
        return res;
    }
};
// @lc code=end

