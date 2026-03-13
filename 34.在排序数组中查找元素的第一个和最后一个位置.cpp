/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int findMid(vector<int>& nums, int left, int right, int target){
        if(left>right) return -1;
        int mid = (left+right)>>1;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) return findMid(nums, left, mid-1, target);
        else return findMid(nums, mid+1, right, target);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firtfind = findMid(nums, left, right, target);
        if(firtfind==-1) return vector<int>{-1, -1};
        
        else {
            vector<int> res;
            int first = firtfind, last = firtfind;
            while(first>=0 && nums[first]==target) first--;
            while(last<nums.size() && nums[last]==target) last++;
            return vector<int>{first+1, last-1};
            }
        
        }
};
// @lc code=end

