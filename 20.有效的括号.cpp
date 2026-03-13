/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    char validnext(char c) {
        switch (c)
        {
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
        default:
            return '\0';
        }
        return '\0';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if(c == ')' || c == '}' || c == ']')
            {
                if (st.empty() || validnext(st.top())!= c) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

