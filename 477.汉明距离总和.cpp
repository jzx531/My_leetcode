/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution {
public:
    // int totalHammingDistance(vector<int>& nums) {
    //     int n = nums.size();
    //     int res = 0;
    //     for(int i = 0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //             res +=hamming(nums[i],nums[j]);
    //         }
    //     }
    //     return res;
    // }
    // int hamming(int x,int y){
    //     int res = 0;
    //     while(x!=0 || y!=0){
    //         res += (x^y)&1;
    //         x = x>>1;
    //         y = y>>1;
    //     }
    //     return res;
    // }
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i<32;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                cnt += (nums[j]>>i)&1;
            }
            res += cnt*(n-cnt);
        }
        return res;
    }
};
// @lc code=end

