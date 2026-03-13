/*
 * @lc app=leetcode.cn id=328 lang=java
 *
 * [328] 奇偶链表
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;

        // 存储偶数和奇数位置的节点
        ArrayList<ListNode> oddlist = new ArrayList<>();
        ArrayList<ListNode> evenlist = new ArrayList<>();
        
        ListNode curr = head;
        int i = 0;
        while (curr != null) {
            if (i % 2 == 0) {
                evenlist.add(curr);
            } else {
                oddlist.add(curr);
            }
            curr = curr.next;
            i++;
        }

        // 重新构建链表
        ListNode dummy = new ListNode(0);  // 创建一个哑结点作为链表头
        ListNode res = dummy;  // 这将指向新链表的头
        ListNode tail = dummy; // 这将追踪新链表中最后一个节点

        // 先添加偶数位置的节点
        for (ListNode node : evenlist) {
            tail.next = node;
            tail = tail.next;
        }

        // 然后添加奇数位置的节点
        for (ListNode node : oddlist) {
            tail.next = node;
            tail = tail.next;
        }

        // 最后设置链表末尾的 `next` 为 null
        tail.next = null;

        return dummy.next;  // 返回重新排列后的链表头
    }
}

// @lc code=end

