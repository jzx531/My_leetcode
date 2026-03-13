/*
 * @lc app=leetcode.cn id=413 lang=java
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public int numberOfArithmeticSlices(int[] nums) {
    int res = 0;
    int n = nums.length;
    if (n < 3) return 0;
    
    int count = 0; // tracks the length of current arithmetic sequence
    
    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            count++;
            res += count;
        } else {
            count = 0;
        }
    }
    
    return res;
}
}
// @lc code=end

