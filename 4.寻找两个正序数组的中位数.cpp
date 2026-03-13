/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     vector<int> nums12 = nums1;
    //     copy(nums2.begin(),nums2.end(),back_inserter(nums12));
    //     sort(nums12.begin(),nums12.end());
    //     int len = nums12.size();
    //     if(len%2==0) return (nums12[len/2-1]+nums12[len/2])/2.0;
    //     else return nums12[len/2];
    // }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n+1)>>1;
        int left =0;
        int right = m;
        while(left<right)
        {
            int i = (left+right)>>1;//需要更短的是nums1,否则nums2会越界
            int j = mid-i;
            if(nums2[j-1]>nums1[i]) left = i+1;
            else right = i;
        }
        int i = left;
        int j = mid-i;
        int nums1leftmax = (i==0)? INT_MIN:nums1[i-1];
        int nums1rightmin = (i==m)? INT_MAX:nums1[i];
        int nums2leftmax = (j==0)? INT_MIN:nums2[j-1];
        int nums2rightmin = (j==n)? INT_MAX:nums2[j];
        if((m+n)%2==0) return (max(nums1leftmax,nums2leftmax)+min(nums1rightmin,nums2rightmin))/2.0;
        else return max(nums1leftmax,nums2leftmax);
    }
};
// @lc code=end

