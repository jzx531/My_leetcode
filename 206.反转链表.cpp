/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        if(!head->next) return head;
        ListNode *cur = head->next;
        ListNode *prev = head;
        while(cur){
            ListNode *tmp = cur ->next;
            prev -> next = tmp;
            cur ->next = head;
            head = cur;
            cur = tmp;
        }
        return head;
    }
};
// @lc code=end

