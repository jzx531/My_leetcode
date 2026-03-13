/*
 * @lc app=leetcode.cn id=1051 lang=java
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
    public int heightChecker(int[] heights) {
        int [] ranked = heights.clone();
        Arrays.sort(ranked);
        int count = 0;
        for (int i = 0; i < heights.length; i++) {
            if(heights[i]!= ranked[i]) count++;
        }
        return count;
    }
}
// @lc code=end

