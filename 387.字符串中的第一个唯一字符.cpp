/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++){
            if(s.find(s[i])==s.rfind(s[i])){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

