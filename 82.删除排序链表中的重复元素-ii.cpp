/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            int count = 1;
            ListNode *next = curr->next;
            while (next && next->val == curr->val) {
                count++;
                next = next->next;
            }
            if (count == 1) {
                prev = curr;
            } else {
                if(prev == nullptr){
                    head = next;
                }
                else{
                    prev->next = next;
                }
            }
            curr = next;
        }
        return head;
    }
};
// @lc code=end

