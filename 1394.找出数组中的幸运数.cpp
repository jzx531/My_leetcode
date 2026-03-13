/*
 * @lc app=leetcode.cn id=1394 lang=cpp
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start
class Solution {
public:
int findLucky(vector<int>& arr) {
    if (arr.empty()) return -1;
    sort(arr.begin(), arr.end(), greater<int>()); // 降序排序
    int current = arr[0], count = 1;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == current) {
            ++count;
        } else {
            if (current == count) {
                return current; // 找到幸运数
            }
            current = arr[i];
            count = 1;
        }
    }
    // 检查最后一个数
    return (current == count) ? current : -1;
}
};
// @lc code=end

