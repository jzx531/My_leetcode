/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
        // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (!head || k == 1) return head;
    
    //     ListNode dummy(0);
    //     dummy.next = head;
    //     ListNode *preHead = &dummy;
    //     ListNode *curr = head;
    
    //     while (curr) {
    //         ListNode *tail = curr;
    //         int count = 0;
    //         // 检查是否剩余k个节点
    //         while (tail && count < k) {
    //             tail = tail->next;
    //             count++;
    //         }
    //         if (count < k) {
    //             break; // 不足k个，不反转
    //         }
    //         // 反转当前组
    //         ListNode *newHead = reverse(curr, tail);
    //         // 链接上一组的尾部到当前组的头部
    //         preHead->next = newHead;
    //         // 更新preHead为当前组的尾部（即反转前的头部）
    //         preHead = curr;
    //         curr = tail; // 移动到下一组
    //     }
    //     return dummy.next;
    // }
    
    // // 反转从head到tail（不包括tail）的链表
    // ListNode* reverse(ListNode* head, ListNode* tail) {
    //     ListNode *prev = tail;
    //     ListNode *curr = head;
    //     while (curr != tail) {
    //         ListNode *next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        if(k == 1) return head;
        if(!head->next) return head;

        ListNode * preHead = nullptr;
        ListNode * prev = head;
        ListNode * curr = head->next;
        ListNode * next = head;
        int i;
        ListNode * res = head;

        while(curr){
            for(i = 1; next!= nullptr&&i <= k; i++)
            {
                if(next->next == nullptr)
                {
                    next = nullptr;
                    break;
                }
                else{next=next->next;}
                
            }
            if(i < k){
                return res;
            }
            else{
                ListNode *tmpHead = prev;
                for(i = 0;i<(k-1);i++)
                {
                    ListNode *tmp = curr ->next;
                    prev -> next = tmp;
                    curr ->next = tmpHead;
                    
                    tmpHead = curr;
                    curr = tmp;
                    if(preHead != nullptr){
                        preHead->next = tmpHead;
                    }
                    else{
                        res = tmpHead;
                    }
                }
            } 
            preHead = prev;
            if(next!= nullptr){
                prev = next;
            }
            else {
                break;
            }
            if(prev->next == nullptr) {
                break;
            }
            curr = prev->next;
        }
        return res;
    }

};
// @lc code=end

