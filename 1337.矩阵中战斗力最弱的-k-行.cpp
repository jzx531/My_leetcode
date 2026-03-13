/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        for(int i=0;i<mat.size();i++){
            res.push_back(i);
        }
        sort(res.begin(),res.end(),[&](int i,int j){
            int cnti = accumulate(mat[i].begin(),mat[i].end(),0);
            int cntj = accumulate(mat[j].begin(),mat[j].end(),0);
            if(cnti==cntj) return i<j;
            return cnti<cntj;
        });
        return vector<int>(res.begin(),res.begin()+k);
    }
};
// @lc code=end

