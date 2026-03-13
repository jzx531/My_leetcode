/*
 * @lc app=leetcode.cn id=486 lang=java
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution {
 

    // public boolean predictTheWinner(int[] nums) {
    //     int len = nums.length;
    //     int[][] memo = new int[len][len];

    //     for (int i = 0; i < len; i++) {
    //         Arrays.fill(memo[i], Integer.MIN_VALUE);
    //     }
    //     return dfs(nums, 0, len - 1, memo) >= 0;
    // }

    //     private int dfs(int[] nums, int i, int j, int[][] memo) {
    //     if (i > j) {
    //         return 0;
    //     }

    //     if (memo[i][j] != Integer.MIN_VALUE) {
    //         return memo[i][j];
    //     }
    //     int chooseLeft = nums[i] - dfs(nums, i + 1, j, memo);
    //     int chooseRight = nums[j] - dfs(nums, i, j - 1, memo);
    //     memo[i][j] = Math.max(chooseLeft, chooseRight);
    //     return memo[i][j];
    // }
    boolean canWin(int[] nums, int start, int end, int scores1,int scores2,boolean player) {
        if (start > end) {
            return scores1 >= scores2;
        }
        if(player){
            return canWin(nums, start + 1, end, scores1 + nums[start], scores2,!player) || canWin(nums, start, end - 1, scores1 + nums[end], scores2,!player);
        }
        else{
            return canWin(nums, start + 1, end, scores1, scores2 + nums[start],!player) && canWin(nums, start, end - 1, scores1, scores2 + nums[end],!player);
        }
        // return false;
    }

   public boolean predictTheWinner(int[] nums) {
     return canWin(nums, 0, nums.length - 1, 0, 0, true);
   }

}
// @lc code=end

