/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char c : address) {
            if (c == '.') {
                res += "[.]";
            } else {
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end

