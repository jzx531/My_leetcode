/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur){
            ListNode *tmppre = dummy;
            ListNode * tmp = dummy->next;
            while(tmp != cur && tmp->val < cur->val)
            {
                tmppre = tmp;
                tmp = tmp->next;
            }
            if(tmp == cur){
                pre = cur;
                cur = cur->next;
            }else{
                ListNode* tmpnext = cur->next;
                tmppre->next = cur;
                cur->next = tmp;
                pre->next = tmpnext;
                cur = tmpnext;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

