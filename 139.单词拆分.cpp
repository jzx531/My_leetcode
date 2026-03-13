/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    // void dfs(string s, vector<string>& wordDict, int start, vector<string> tmp,bool& flag) {
    //     if(flag) return;
    //     if (start == s.size()) {
    //         flag = true;
    //         return;
    //     }
    //     for(int i = 0;i < wordDict.size();i++)
    //     {
    //         if (s.substr(start, wordDict[i].size()) == wordDict[i]) {
    //             tmp.push_back(wordDict[i]);
    //             dfs(s, wordDict, start + wordDict[i].size(), tmp, flag);
    //             tmp.pop_back();
    //         }
    //     }
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     vector<string> tmp;
    //     bool flag = false;
    //     dfs(s, wordDict, 0, tmp, flag);
    //     return flag;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }


};
// @lc code=end

