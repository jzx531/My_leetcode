/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
string reverseOnlyLetters(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        // 移动 left 指针直到找到一个字母
        while (left < right && !isalpha(s[left])) {
            left++;
        }
        // 移动 right 指针直到找到一个字母
        while (left < right && !isalpha(s[right])) {
            right--;
        }
        // 交换字母
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}
};
// @lc code=end

