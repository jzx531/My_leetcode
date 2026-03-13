/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    // void dfs(vector<vector<int>>& grid, int i, int j, int& res, int& temp) {
    //     if(temp+grid[i][j] > res) return;
    //     if (i == grid.size() - 1 && j == grid[0].size() - 1) {
    //         res = min(res, temp + grid[i][j]);
    //         return;
    //     }
    //     if(i < grid.size() - 1) {
    //         temp += grid[i][j];
    //         dfs(grid, i + 1, j, res, temp);
    //         temp -= grid[i][j];
    //     }
    //     if(j < grid[0].size() - 1) {
    //         temp += grid[i][j];
    //         dfs(grid, i, j + 1, res, temp);
    //         temp -= grid[i][j];
    //     }
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int res = INT_MAX;
    //     int temp = 0;
    //     dfs(grid, 0, 0, res, temp);
    //     return res;
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

