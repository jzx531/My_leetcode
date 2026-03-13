/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1) return;
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int mid = (n+1)/2;
        for(int i=0;i<mid;i++){
            nums[i*2] = arr[mid-i-1];
            nums[i*2+1] = arr[n-i-1];
        }
    }
};
// @lc code=end

