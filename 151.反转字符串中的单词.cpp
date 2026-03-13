/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        string res;
        string tmp;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' ') {
                tmp += s[i];
            }
            else {
                if(!tmp.empty()) {
                    reverse(tmp.begin(), tmp.end());
                    res += tmp + " ";
                    tmp.clear();
                }
            }
        }
        // res.pop_back();
        if(!tmp.empty()) {
        reverse(tmp.begin(), tmp.end());
        res += tmp;
        }
        else{
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end

