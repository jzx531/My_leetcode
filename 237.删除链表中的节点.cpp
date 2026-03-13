/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while(node->next){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        if(prev) prev->next = nullptr;
        // delete node;
    }
};
// @lc code=end

