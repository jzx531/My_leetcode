/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // 空字符串和空模式匹配
        dp[0][0] = true;
        
        // 处理模式如a* a*b* a*b*c*等可以匹配空字符串的情况
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 当前字符匹配
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // 遇到 '*' 的情况
                else if (p[j - 1] == '*') {
                    // 匹配0次
                    dp[i][j] = dp[i][j - 2];
                    // 如果 '*' 前的字符匹配，可以考虑匹配1次或多次
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                // 其他情况不匹配
                else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[m][n];
    }
};
// @lc code=end

