/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * insertplace = nullptr;
        ListNode * p = head;
        while(p && p->val < x )
        {
            insertplace = p;
            p = p->next;
        }
        ListNode * prev = insertplace;
        ListNode * insertnext = p;
        while(p!= nullptr)
        {
            if(p->val >= x){
                prev = p;
                p = p->next;
            }
            else{
                ListNode * tmp = p->next;
                if(insertplace !=nullptr)
                {
                    insertplace->next = p;
                }
                else{
                    head = p;
                }
                prev->next = tmp;
                p->next = insertnext;
                insertplace = p;
                p = tmp;
            }
        }
        return head;
    }
};
// @lc code=end

