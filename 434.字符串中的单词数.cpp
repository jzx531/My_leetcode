/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        string word = "";
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    res++;
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            res++;
        }
        return res;
    }
};
// @lc code=end

