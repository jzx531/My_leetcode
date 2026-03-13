/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* sortList(ListNode* head) {
    if (!head) return nullptr;  // 处理空链表情况
    
    vector<ListNode*> nodes;
    while (head) {
        nodes.push_back(head);
        head = head->next;
    }
    
    sort(nodes.begin(), nodes.end(), [](ListNode* a, ListNode* b) {
        return a->val < b->val;
    });
    
    // 重新连接节点
    for (int i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes.back()->next = nullptr;  // 最后一个节点的next置空
    
    return nodes.front();
}
};
// @lc code=end

