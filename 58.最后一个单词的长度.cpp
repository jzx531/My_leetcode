/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        reverse(s.begin(),s.end());
        int i = 0,j = 0;
        while(s.at(j) ==' '){
            ++j;
        }
        while(s.at(j) !=' '){
            ++i;
            ++j;
            if(j == s.size()){
                break;
            }
        }
        return i;
    }
};
// @lc code=end

