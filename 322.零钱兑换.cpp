/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
    // void dfs(int sum, int &mount,int index, vector<int>& coins,int count,int& res)
    // {
    //     // if(res<(mount+1)) return;
    //     if(sum==mount){
    //         res = min(res,count);
    //         return;
    //     }
    //     for(int i=index;i<coins.size();i++){
    //         if(sum+coins[i]<=mount){
    //             dfs(sum+coins[i],mount,i,coins,count+1,res);
    //         }
    //     }
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     sort(coins.begin(),coins.end());
    //     int n=coins.size();
    //     for(int i=n-1;i>=0;i--){
    //         if(coins[i]>amount)
    //         {
    //             coins.erase(coins.begin()+i);
    //         }
    //     }
    //     reverse(coins.begin(),coins.end());
    //     int res=amount+1;
    //     dfs(0,amount,0,coins,0,res);
    //     return res==amount+1?-1:res;
    // }
};
// @lc code=end

