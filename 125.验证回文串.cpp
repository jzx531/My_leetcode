/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for(auto c : s)
        {
            if('a'<=c && c<='z' )
            {
                tmp += c;
            }
            else if('A'<=c && c<='Z')
            {
                tmp += c + 32;
            }
            else if('0'<=c && c<='9')
            {
                tmp += c;
            }
        }
        string reverse_tmp = tmp;
        reverse(reverse_tmp.begin(),reverse_tmp.end());
        return tmp == reverse_tmp;
    }
};
// @lc code=end

