/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res = intervals;
        sort(res.begin(), res.end());
        int n = res.size();
        for(int i = 1; i < n; i++){
            if(res[i][0] <= res[i-1][1]){
                res[i][0] = min(res[i][0], res[i-1][0]);
                res[i][1] = max(res[i][1], res[i-1][1]);
                res.erase(res.begin()+i-1);
                i--;
                n--;
            }
        }
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
// @lc code=end

