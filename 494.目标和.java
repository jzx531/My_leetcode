/*
 * @lc app=leetcode.cn id=494 lang=java
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
    private int dfs(int[] nums, int target, int index, int sum) {
        if (index == nums.length) {
            return sum == target ? 1 : 0;
        }
        // 选择加号
        int add = dfs(nums, target, index + 1, sum + nums[index]);
        // 选择减号
        int sub = dfs(nums, target, index + 1, sum - nums[index]);
        return add + sub;
    }

    public int findTargetSumWays(int[] nums, int target) {
        return dfs(nums, target, 0, 0);
    }
}

// @lc code=end

