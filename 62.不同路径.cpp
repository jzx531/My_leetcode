/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // void dfs(int m, int n, int x, int y,int &res)
    // {
    //     if (x == m - 1 && y == n - 1) { res++; return;}
    //     if(x == m - 1) dfs(m, n, x, y + 1, res);
    //     else if(y == n - 1) dfs(m, n, x + 1, y, res);
    //     else {
    //         dfs(m, n, x + 1, y, res);
    //         dfs(m, n, x, y + 1, res);
    //     }
    // }
    // int uniquePaths(int m, int n) {
    //     int res = 0;
    //     dfs(m, n, 0, 0, res);
    //     return res;
    // }
    // long long factorial(int n) {
    //     long long result = 1;
    //     for (int i = 2; i <= n; ++i)
    //         result *= i;
    //     return result;
    // }
    
    // long long combination(int n, int r) {
    //     return factorial(n) / (factorial(r) * factorial(n - r));
    // }

    // int uniquePaths(int m,int n)
    // {
    //     if(m==1 || n==1) return 1;
    //     if(m<n) swap(m,n);
    //     long long res = m+n-2;
    //     for(int i = m+n-3;i>m-1;--i)
    //     {
    //         res = res*i;
    //     }
    //     return res/factorial(n-1);
    // }
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

