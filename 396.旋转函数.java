/*
 * @lc app=leetcode.cn id=396 lang=java
 *
 * [396] 旋转函数
 */

// @lc code=start

import java.util.Arrays;

public class Solution {
//     public int maxRotateFunction(int[] nums) {
//         int[] sumrows = new int[nums.length];
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 sumrows[i] += nums[(i + j) % n] * j;
//             }
//         }
//         Arrays.sort(sumrows);
//         return sumrows[n - 1];
//     }

    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum += i * nums[i];
        }
        int curSum = maxSum;
        for (int i = 1; i < n; i++) {
            curSum = curSum + sum - n * nums[n - i];
            maxSum = Math.max(maxSum, curSum);
        }
        return maxSum;
    }
}

// @lc code=end

