/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * tail = head;
        if(!head ||!head->next) return head;
        int len = 1;
        while(tail->next) {
            tail = tail->next;
            len++;
        }
        for(int i = 0; i < len-k%len; i++) {
            tail->next = head;
            ListNode * tmp = head;
            head = head->next;
            tmp->next = nullptr;
            tail = tmp;
        }
        return head;
    }
};
// @lc code=end

