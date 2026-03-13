/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // void climb(int n,int cur,int & count)
    // {
    //     if(cur==n){
    //         count++;
    //         return;
    //     }
    //     else if(cur>n){
    //         return;
    //     }
    //     else{
    //         climb(n,cur+1,count);
    //         climb(n,cur+2,count);
    //     }
    // }
    // int climbStairs(int n) {
    //     int res=0;
    //     climb(n,0,res);
    //     return res;
    // }
    unordered_map<int,int> dp;
    int climbStairs(int n) {
        if(n == 0) return  0;
        if(n == 1) return  1;
        if(n == 2) return  2;
        if(dp[n]!=0) return dp[n];
        return dp[n]=climbStairs(n-1) + climbStairs(n-2);
    }
};
// @lc code=end

