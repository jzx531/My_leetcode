/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        int len = 0;
        vector<ListNode*> vec;
        ListNode* p = head;
        while (p) {
            vec.push_back(p);
            p = p->next;
            len++;
        }
        int mid = len / 2;
        for (int i = 0; i < mid; i++) {
            vec[i]->next = vec[len - 1 - i];
            vec[len - 1 - i]->next = vec[i + 1];
        }
        vec[mid]->next = nullptr;
    }
};

// @lc code=end

