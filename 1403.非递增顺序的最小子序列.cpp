/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); // 降序排序
        int total = accumulate(nums.begin(), nums.end(), 0); // 计算总和
        int sum = 0;
        vector<int> res;
        for (int num : nums) {
            sum += num;
            res.push_back(num);
            if (sum > total - sum) { // 子序列和 > 剩余和
                break;
            }
        }
        return res;
    }
};
// @lc code=end

