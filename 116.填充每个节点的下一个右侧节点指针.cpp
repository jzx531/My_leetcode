/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect(Node* root,int level,vector<Node*> &nodes)
    {
        if(root==nullptr) return;
        
        if(level>=nodes.size()) nodes.push_back(root);
        else {
            nodes[level]->next = root;
            nodes[level] = root;
        }
        connect(root->left,level+1,nodes);
        connect(root->right,level+1,nodes);
    }
    Node* connect(Node* root) {
        vector<Node*> nodes;
        connect(root,0,nodes);
        return root;
    }
};
// @lc code=end

