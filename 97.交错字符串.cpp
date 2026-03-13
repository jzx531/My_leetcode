/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    // bool isInterleave(string s1, string s2, string s3) {
    //     int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    //     if (len1 + len2 != len3) return false;
    //     vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
    //     dp[0][0] = true;
    //     for (int i = 1; i <= len1; i++) {
    //         dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    //     }
    //     for (int j = 1; j <= len2; j++) {
    //         dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    //     }
    //     for (int i = 1; i <= len1; i++) {
    //         for (int j = 1; j <= len2; j++) {
    //             dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
    //         }
    //     }
    //     return dp[len1][len2];
    // }
// void dfs(string s1, string s2, string s3, int i, int j, int k,bool &flag) {
//     if(flag) return;
//     if (i == s1.length() && j == s2.length() && k == s3.length()) {
//         flag = true;
//         return;
//     }
//     int count = 0;
//     if (i < s1.length() && s1[i] == s3[k]) {
//         dfs(s1, s2, s3, i+1, j, k+1, flag);
//     }
//     if (j < s2.length() && s2[j] == s3[k]) {
//         dfs(s1, s2, s3, i, j+1, k+1, flag);
//     }
// }
// bool isInterleave(string s1, string s2, string s3) {
//     int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
//     if (len1 + len2 != len3) return false;
//     bool flag = false;
//     dfs(s1, s2, s3, 0, 0, 0, flag);
//     return flag;
// }
bool isInterleave(string s1, string s2, string s3) {
    auto f = vector < vector <int> > (s1.size() + 1, vector <int> (s2.size() + 1, false));

    int n = s1.size(), m = s2.size(), t = s3.size();

    if (n + m != t) {
        return false;
    }

    f[0][0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
            }
            if (j > 0) {
                f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }

    return f[n][m];
}

};
// @lc code=end

