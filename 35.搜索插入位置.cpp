/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int left,int right) 
    {
        if(left>right){
            return left;    
        }
        int mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return binarySearch(nums,target,left,mid-1);
        }
        else{
            return binarySearch(nums,target,mid+1,right);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};
// @lc code=end

