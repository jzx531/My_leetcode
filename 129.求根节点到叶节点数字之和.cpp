/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    void inorder(TreeNode* root, vector<int>& res,int tmp)
    {
        if (root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            res.push_back(tmp*10+root->val);
            return;
        }
        inorder(root->left, res, tmp*10+root->val);
        inorder(root->right, res, tmp*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        inorder(root, res, 0);
        int sum = 0;
        for(int i=0;i<res.size();i++)
        {
            sum += res[i];
        }
        return sum;
    }
};


// @lc code=end

