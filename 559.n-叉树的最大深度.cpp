/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    void DFS(Node* root,int path,int & maxDepth) {
         if(root == nullptr) return;
         path++;
         if(path > maxDepth) maxDepth = path;
         for(auto child : root->children) {
             DFS(child,path,maxDepth);
         }
    }
    int maxDepth(Node* root) {
        int res = 0;
        DFS(root,0,res);
        return res;
    }
};
// @lc code=end

