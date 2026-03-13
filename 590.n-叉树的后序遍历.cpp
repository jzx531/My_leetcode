/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root, vector<int>& res)
    {
        if (!root) return;
        for (auto child : root->children) {
            dfs(child, res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
// @lc code=end

