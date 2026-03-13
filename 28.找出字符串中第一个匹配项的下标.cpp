/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.size() < needle.size()) return -1;
        bool find;
        for(int i = 0; i <= haystack.size() - needle.size(); i++){
            find = true;
            for(int j =0;j<needle.size();j++){
                if(haystack[i+j]!= needle[j]){
                    find = false;
                    break;
                }
            }
            if(find){
              return i;
            }
        }
        return -1;
    }
};
// @lc code=end

