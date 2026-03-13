/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    // double findMaxAverage(vector<int>& nums, int k) {
    //     int maxVal = INT_MIN;
    //     for(int i=0;i<=nums.size()-k;i++){
    //         maxVal = max(maxVal,accumulate(nums.begin()+i,nums.begin()+i+k,0)); 
    //     }
    //     return (double)maxVal/k;
    // }
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) return 0; // 处理 k > nums.size() 的情况
        
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum; // 初始化为第一个窗口的和
        for (int i = 1; i <= nums.size() - k; ++i) {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};
// @lc code=end

