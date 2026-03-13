/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode *pA = headA, *pB = headB;
    //     while (pA) {
    //         while(pB)
    //         {
    //             if (pA == pB) {
    //                 return pA;
    //             }
    //             pB = pB->next;
    //         }
    //         pA = pA->next;
    //         pB = headB;
    //     }
    //     return NULL;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA ||!headB) return NULL;
        ListNode *pA = headA, *pB = headB;
        stack<ListNode*> sA;
        stack<ListNode*> sB;
        while(pA){
            sA.push(pA);
            pA = pA->next;
        }
        while(pB){
            sB.push(pB);
            pB = pB->next;
        }
        ListNode *res = NULL;
        while(!sA.empty() &&!sB.empty()){
            if(sA.top() == sB.top()){
                res = sA.top();
                sA.pop();
                sB.pop();
            }
            else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

