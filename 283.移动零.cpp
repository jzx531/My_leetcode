/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         if(nums[i] == 0)
    //         {
    //             for (int j = i + 1; j < n; j++) {
    //                 if (nums[j] != 0) {
    //                     swap(nums[i], nums[j]);
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return;
    // }
    // void moveZeroes(vector<int>& nums) {
    //     int n = nums.size();
    //     for (int i = n-1; i >= 0; i--) {
    //         if(nums[i] == 0)
    //         {
    //             nums.erase(nums.begin() + i);
    //             nums.push_back(0);
    //         }
    //     }
    //     return;
    // }
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
// @lc code=end

