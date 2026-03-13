/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start
class Solution {
public:
int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int threshold = n / 4;
    int i = 0;
    while (i < n) {
        int current = arr[i];
        int count = 0;
        while (i < n && arr[i] == current) {
            count++;
            i++;
        }
        if (count > threshold) {
            return current;
        }
    }
    return -1; // 题目保证有解，这一行不会执行
}
};
// @lc code=end

