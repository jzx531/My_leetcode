/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs[0]=="") return "";
        string res="";
        char c = strs[0].at(0);
        for (int i = 0; i < strs[0].size(); i++) {
            for(auto s : strs){
                if(i >= s.size()|| s.at(i)!= c)
                {
                    return res;
                }
            }
            res += c;
            if(i == strs[0].size()-1) return res;
            c = strs[0].at(i+1);
        }
        return "";
    }
};
// @lc code=end

