/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    
    int fib(int n) {
        static unordered_map<int,int> dp;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(dp.count(n)) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }
};
// @lc code=end

