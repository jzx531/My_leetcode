/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    void binarySearch(vector<int>& nums, int left, int right, int& res){
        if(left == right){
            res = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        if(nums[mid] > nums[right]){
            binarySearch(nums, mid+1, right, res);
        }else{
            binarySearch(nums, left, mid, res);
        }
    }
    int findMin(vector<int>& nums) {
        int res = 0;
        binarySearch(nums, 0, nums.size()-1, res);
        return res;
    }
};
// @lc code=end

