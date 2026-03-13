/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    // vector<int> countSmaller(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> res(n, 0);
    //     for(int i = n-1;i>=0;i--)
    //     {
    //         int count = 0;
    //         for(int j = i+1;j<n;j++)
    //         {
    //             if(nums[j]<nums[i])
    //             {
    //                 count++;
    //             }
    //         }
    //         res[i] = count;
    //     }
    //     return res;
    // }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<pair<int, int>> numsWithIndex; // 存储数值和原始索引
        
        for (int i = 0; i < n; ++i) {
            numsWithIndex.emplace_back(nums[i], i);
        }
        
        mergeSort(numsWithIndex, 0, n - 1, res);
        
        return res;
    }
    
private:
    void mergeSort(vector<pair<int, int>>& nums, int low, int high, vector<int>& res) {
        if (low >= high) {
            return;
        }
        
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid, res);     // 排序左半部分
        mergeSort(nums, mid + 1, high, res); // 排序右半部分
        
        // 合并两个有序数组
        vector<pair<int, int>> tmp;
        int left = low, right = mid + 1;
        
        while (left <= mid && right <= high) {
            if (nums[left].first <= nums[right].first) {
                tmp.push_back(nums[left]);
                res[nums[left].second] += right - (mid + 1); // 统计右边比当前数小的个数
                ++left;
            } else {
                tmp.push_back(nums[right]);
                ++right;
            }
        }
        
        // 处理剩余元素
        while (left <= mid) {
            tmp.push_back(nums[left]);
            res[nums[left].second] += right - (mid + 1); // 统计右边比当前数小的个数
            ++left;
        }
        
        while (right <= high) {
            tmp.push_back(nums[right]);
            ++right;
        }
        
        // 将排序后的结果拷贝回原数组
        for (int i = low; i <= high; ++i) {
            nums[i] = tmp[i - low];
        }
    }
};
// @lc code=end

