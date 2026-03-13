/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode * prev = head;
        ListNode *curr=prev->next;
        ListNode *dummy=new ListNode(0);
        head = curr;
        while(1){
            ListNode *temp=curr->next;
            dummy->next = curr;
            prev->next=temp;
            curr->next=prev;
            if(!temp||!temp->next) break;
            dummy=prev;
            prev=temp;
            curr=temp->next;
        }
        return head;
    }
};
// @lc code=end

