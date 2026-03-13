/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string Code(string s) {
        string res = "";
        int i = 0;
        cout << s.size() << endl;
        while (i < s.size()) {
            int count = 1;
            while (i < (s.size() - 1) && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            res += to_string(count) + s[i];  // Always use s[i], not s[i-1]
            i++;  // Move to the next character
        }
        return res;  // Must return the result
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n-1);
        return Code(s);
    }
};
// @lc code=end

