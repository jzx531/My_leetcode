/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
class Solution {
public:
    // int bulbSwitch(int n) {
    //     vector<int> dp(n,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j<n;j+=(i+1))
    //         {
    //             if(dp[j]==0)
    //             {
    //                 dp[j]=1;
    //             }
    //             else
    //             {
    //                 dp[j]=0;
    //             }
    //         }
    //     }
    //     return accumulate(dp.begin(),dp.end(),0);
    // }
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
// @lc code=end

