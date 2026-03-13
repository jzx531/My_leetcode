/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int n=nums.size();
    //     int min_len=n+1;
    //     for(int i=0;i<n;i++){
    //         int sum=nums[i];
    //         if(sum>=target) return 1;
    //         for(int j=i+1;j<n;j++){
    //             sum+=nums[j];
    //             if(j-i+1>=min_len) break;
    //             if(sum>=target){
    //                 min_len=min(min_len,j-i+1);
    //                 break;
    //             }
    //         }
    //     }
    //     return min_len==n+1?0:min_len;
    // }

    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_len = INT_MAX;
        int left = 0;
        int current_sum = 0;
        
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            while (current_sum >= target) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        
        return (min_len != INT_MAX) ? min_len : 0;
    }
};
// @lc code=end

