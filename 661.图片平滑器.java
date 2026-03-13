/*
 * @lc app=leetcode.cn id=661 lang=java
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < m && l >= 0 && l < n) {
                            sum += img[k][l];
                            count++;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
}
// @lc code=end

