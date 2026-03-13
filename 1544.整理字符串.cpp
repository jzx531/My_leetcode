/*
 * @lc app=leetcode.cn id=1544 lang=cpp
 *
 * [1544] 整理字符串
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        string res;
        char cur,next;
        int i = 1;
        res.push_back(s[0]);
        while (i < s.size()) {
            if(!res.empty() && abs(res.back()-s[i])==32){
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
            }
            ++i;
        }
        return res;
    }
};
// @lc code=end

