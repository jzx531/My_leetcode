/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
public:
    // int removePalindromeSub(string s) {
    //     if(s.empty()) return 0;
    //     if(s.size() == 1) return 1;
    //     int n = s.size();
    //     int left = 0, right = n-1;
    //     int max_len = 0;
    //     for(int i = 0; i < s.size(); i++)
    //     {
    //         int tmpleft = i, tmpright = i;
    //         while((tmpleft >= 0 && tmpright < n )&& s[tmpleft] == s[tmpright])
    //         {
    //             if((tmpright - tmpleft + 1) > max_len)
    //             {
    //                 max_len = tmpright - tmpleft + 1;
    //                 left = tmpleft;
    //                 right = tmpright;
    //             }
    //             tmpleft--;
    //             tmpright++;
    //         }
    //     }
    //     for(int i = 0; i < s.size()-1; i++)
    //     {
    //         int tmpleft = i, tmpright = i+1;
    //         while((tmpleft >= 0 && tmpright < n )&& s[tmpleft] == s[tmpright])
    //         {
    //             if((tmpright - tmpleft + 1) > max_len)
    //             {
    //                 max_len = tmpright - tmpleft + 1;
    //                 left = tmpleft;
    //                 right = tmpright;
    //             }
    //             tmpleft--;
    //             tmpright++;
    //         }
    //     }
    //     s = s.substr(0, left) + s.substr(right+1);
    //     return 1+removePalindromeSub(s);
    // }
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }
        if (equal(s.begin(), s.end(), s.rbegin())) {
            return 1;
        }
        return 2;
    }
};
// @lc code=end

