/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int findRotate(vector<int>& nums, int left,int right)
    {
        if(left>=right)
            return right;
        int mid=(left+right)>>1;
        if(nums[mid]>=nums[right])
        {
            return findRotate(nums,mid+1,right);
        }
        else{
            return findRotate(nums,left,mid);
        }
    }
    int binary_search(vector<int>& nums, int left,int right,int target)
    {
        while(left<right)
        {
            int mid=(left+right)>>1;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        if(left >= right){
            return nums[left]==target?left:-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        if(nums.size()==1)
            return nums[0]==target?0:-1;
        int place = findRotate(nums,0,nums.size()-1);
        if (place==0) return binary_search(nums,0,nums.size()-1,target);
        if(target>nums[nums.size()-1])
            return binary_search(nums,0,place-1,target);
        else if(target<nums[0]){
            return binary_search(nums,place,nums.size()-1,target);
        }
        else{
            return max(binary_search(nums,0,place-1,target),binary_search(nums,place,nums.size()-1,target));
        } 
    }
};
// @lc code=end

