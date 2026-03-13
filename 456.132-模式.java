/*
 * @lc app=leetcode.cn id=456 lang=java
 *
 * [456] 132 模式
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    // public boolean find132pattern(int[] nums) {
    //     int n = nums.length;
    //     if (n < 3) {
    //         return false;
    //     }
    //     for(int i = 0; i < n-2; i++)
    //     {
    //         for(int j = i+1; j < n-1; j++)
    //         {
    //             for(int k = j+1; k < n; k++)
    //             {
    //                 if(nums[i] < nums[j] && nums[k] < nums[j]&&nums[k] > nums[i])
    //                 {
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        Deque<Integer> d = new ArrayDeque<>();
        int k = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < k) return true;
            while (!d.isEmpty() && d.peekLast() < nums[i]) {
                // 事实上，k 的变化也具有单调性，直接使用 k = pollLast() 也是可以的
                k = Math.max(k, d.pollLast()); 
            }
            d.addLast(nums[i]);
        }
        return false;
    }

    
}
// @lc code=end

