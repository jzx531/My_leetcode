/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
    Solution(ListNode* head) {
        srand(time(0));
        this->head = head;
        this->size = 0;
        while(head){
            size++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % size;
        ListNode* p = head;
        while(idx--){
            p = p->next;
        }
        return p->val;
    }
    private:
        ListNode* head;
        int size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

