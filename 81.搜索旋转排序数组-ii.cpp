/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool binarySearchGreater(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return false;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (target <= nums[mid]) {
            return binarySearchGreater(nums, target, left, mid - 1);
        } 
        else {
            return binarySearchGreater(nums, target, mid + 1, right);
        }
    }
    bool binarySearchLess(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return false;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (target >= nums[mid]) {
            return binarySearchLess(nums, target, mid + 1, right);
        } 
        else {
            return binarySearchLess(nums, target, left, mid - 1);
        }
    }
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        else if (nums.size() == 1) {
            return nums[0] == target;
        }
        
        int k = 0;
        while(k < nums.size()-1&&nums[k] <= nums[k+1]){
            k++;
        }
        return binarySearchGreater(nums, target, 0, k) || binarySearchGreater(nums, target, k+1, nums.size()-1);
    }
};
// @lc code=end

