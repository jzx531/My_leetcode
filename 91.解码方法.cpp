/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    // void backtrace(string s,int index,int &res)
    // {
    //     if(index == s.size()){
    //         res++;
    //         return;
    //     }
    //     if(s[index]=='0') return;
    //     if(s[index]=='1'){
    //         if(index == (s.size()-1)){
    //             backtrace(s,index+1,res);
    //         }
    //         else if(index ==(s.size()-2))
    //         {
    //             backtrace(s,index+1,res);
    //             backtrace(s,index+2,res);
    //         }
    //         else{
    //             backtrace(s,index+1,res);
    //             backtrace(s,index+2,res);
    //         }  
    //     }
    //     else if(s[index]=='2')
    //     {
    //         if(index == (s.size()-1))
    //         {
    //             backtrace(s,index+1,res);
    //         }
    //         else 
    //         {
    //             if(s[index+1]<'7')
    //             {
    //                 backtrace(s,index+1,res);
    //                 backtrace(s,index+2,res);
    //             }
    //             else{
    //                 backtrace(s,index+1,res);
    //             }
    //         }
    //     }
    //     else{
    //         backtrace(s,index+1,res);
    //     }
    // }
    // int numDecodings(string s) {
    //     if(s[0]=='0') return 0;
    //     int res=0;
    //     backtrace(s,0,res);
    //     return res;
    // }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
// @lc code=end

