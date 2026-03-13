/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while(res.size()>1 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

