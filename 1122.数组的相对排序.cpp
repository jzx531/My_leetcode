/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res = arr1;
        sort(res.begin(), res.end(), [&arr2](int a, int b) {
            auto it_a = find(arr2.begin(), arr2.end(), a);
            auto it_b = find(arr2.begin(), arr2.end(), b);
            if (it_a != arr2.end() && it_b != arr2.end()) {
                return it_a < it_b; // 如果都在 arr2 中，按 arr2 的顺序排序
            } else if (it_a != arr2.end()) {
                return true; // a 在 arr2 中，b 不在，a 排在前面
            } else if (it_b != arr2.end()) {
                return false; // b 在 arr2 中，a 不在，b 排在前面
            } else {
                return a < b; // 都不在 arr2 中，按升序排列
            }
        });
        return res;
    }
};
// @lc code=end

