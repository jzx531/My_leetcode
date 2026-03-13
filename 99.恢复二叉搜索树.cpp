/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    pair<int,int> findExchanged(TreeNode* root) {
        if (root == nullptr) return {INT_MAX, INT_MAX};
        vector<int> nums;
        inorder(root, nums);

        int n = nums.size();
        int num1 , num2;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < n; i++) {
            if (nums[i] != sorted[i]) {
                num1 = nums[i];
                num2 = sorted[i];
                break;
            }
        }
        // cout<<num1<<" "<<num2<<endl;
        return {num1, num2};
    }

    TreeNode* recoverTree(TreeNode* root,pair<int,int> p,int count) {
        if (root == nullptr) return nullptr;
        if (root->val == p.first) {
            root->val = p.second;
            count++;
        }
        else if(root->val == p.second) {
            root->val = p.first;
            count++;
        }
        if (count == 2) return root;
        recoverTree(root->left, p, count);
        recoverTree(root->right, p, count);
        return root;
    }
    TreeNode* recoverTree(TreeNode* root) {
        pair<int,int> p = findExchanged(root);
        return recoverTree(root, p, 0);
    }

};


// @lc code=end

