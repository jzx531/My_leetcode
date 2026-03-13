/*
 * @lc app=leetcode.cn id=922 lang=java
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        Stack<Integer> odd = new Stack<>();
        Stack<Integer> even = new Stack<>();
        for (int num : nums) {
            if (num % 2 == 0) {
                even.push(num);
            } else {
                odd.push(num);
            }
        }
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                result[i] = even.pop();
            } else {
                result[i] = odd.pop();
            }
        }
        return result;
    }
}
// @lc code=end

