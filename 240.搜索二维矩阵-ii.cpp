/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool binarySearch(vector<vector<int>>& nums, int target, int left, int right, int top, int bottom){
        if(left>right || top>bottom) return false;
        int mid1 = (left+right)/2;
        int mid2 = (top+bottom)/2;
        if(nums[mid1][mid2]==target) return true;
        if(nums[mid1][mid2]>target) return binarySearch(nums,target,left,mid1-1,top,bottom)||binarySearch(nums,target,left,right,top,mid2-1);
        if(nums[mid1][mid2]<target) return binarySearch(nums,target,mid1+1,right,top,bottom)||binarySearch(nums,target,left,right,mid2+1,bottom);
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0,right = matrix.size()-1;
        int top = 0,bottom = matrix[0].size()-1;
        return binarySearch(matrix,target,left,right,top,bottom);
    }
};
// @lc code=end

