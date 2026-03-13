/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for(auto p : mp){
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end

