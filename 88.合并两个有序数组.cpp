/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n ==0) return;
        if(m == 0) {nums1 = nums2;return;}
        copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end

