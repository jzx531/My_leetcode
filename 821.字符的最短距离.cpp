/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == c) res.push_back(0);
            else {
                int min_dist = INT_MAX;
                for(int j = i-1; j >= 0; j--){
                    if(s[j] == c) {
                        min_dist = min(min_dist, i-j);
                        break;
                    }
                }
                for(int j = i+1; j < n; j++){
                    if(s[j] == c) {
                        min_dist = min(min_dist, j-i);
                        break;
                    }
                }
                res.push_back(min_dist);
            }
            
        }
        return res;
    }
};
// @lc code=end

