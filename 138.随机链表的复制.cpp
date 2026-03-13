/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        vector<Node*> nodes;
        vector<Node*> origins;
        Node* p = head;
        while(p){
            origins.push_back(p);
            nodes.push_back(new Node(p->val));
            p = p->next;
        }
        for(int i=0;i<nodes.size();i++){
            if(i+1<nodes.size()){
                nodes[i]->next = nodes[i+1];
            }
            if(origins[i]->random){
                int j = find(origins.begin(),origins.end(),origins[i]->random) - origins.begin();
                nodes[i]->random = nodes[j];
            }
        }
        return nodes[0];
    }
};
// @lc code=end

