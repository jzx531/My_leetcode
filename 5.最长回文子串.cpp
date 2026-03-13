/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, max_len = 1;
        
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);     // 奇数长度情况
            int len2 = expandAroundCenter(s, i, i + 1); // 偶数长度情况
            int len = max(len1, len2);
            
            if (len > max_len) {
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, max_len);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

};
// @lc code=end

