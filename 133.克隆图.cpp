/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<int, Node*> visicon;
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr) return nullptr;
        
        if(node->neighbors.empty()) {
            visicon[node->val] = new Node(node->val);
            return new Node(node->val);
        }
        if(visicon.count(node->val)) return visicon[node->val];
        
        Node *new_node = new Node(node->val);
        visicon[node->val] = new_node;

        for (Node* neighbor : node->neighbors)
        {
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return new_node;
    }
};
// @lc code=end

