/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] ) return 0;
        if(obstacleGrid[m-1][n-1]) return 0;
        if (m == 1 || n == 1)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(obstacleGrid[i][j]) return 0;
                }
            }
            return 1;
        }
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    if(obstacleGrid[i][j]) dp[i][j] = 0;
                    else dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0) {
                    if (obstacleGrid[i][j]) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j];
                }
                else {
                    if(obstacleGrid[i][j] ) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

