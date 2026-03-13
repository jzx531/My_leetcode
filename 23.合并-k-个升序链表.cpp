/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    struct MyCompare
    {
        bool operator()(const int& a, const int& b) const
        {
            return a > b;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode * tail = dummy;
        priority_queue<int, vector<int>, MyCompare> q;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]){
                q.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        while(!q.empty())
        {
            tail->next = new ListNode(q.top());
            q.pop();
            tail = tail->next;
        }
        return dummy->next;
    }
};
// @lc code=end

