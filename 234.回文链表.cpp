/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(vector<int>& nums) {
        for(int i = 0; i < nums.size() / 2; i++)
        {
            if(nums[i] != nums[nums.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return isPalindrome(nums);
    }
};
// @lc code=end

