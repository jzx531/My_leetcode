/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        vector<int> res;
        sort(nums2.begin(), nums2.end());
        for(int num : nums1){
            auto ins = s.insert(num);
            if(!ins.second){
                continue;
            }
            auto ret = binarySearch(nums2, num, 0, nums2.size() - 1);
            if(ret){
                res.push_back(num);
            }
        }
        return res;
    }

};
// @lc code=end

