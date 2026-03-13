/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int n) {
        if(n == 1) return false;
        vector<int> dp(n+1, 0);
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i % j == 0 && dp[i-j] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n] == 1;
    }
};
// @lc code=end

