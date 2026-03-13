/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        vector<string> tmp;
        if(digits.empty()) return res;
        bool first = true;
        for (char c: digits){
            for (char d: mp[c]) {
                if(first){
                    res.push_back(string(1,d));
                }
                else{
                    for(string s: res){
                        tmp.push_back(s + d);
                    }
                }
            }
            first = false;
            if(!tmp.empty()){
                res = tmp;
                tmp.clear();
            }
        }
        return res;
    }
};
// @lc code=end

