/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& candidates,int start,int target,vector<int> path,int sum,vector<vector<int>>& res)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            res.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(sum+candidates[i]>target)
                continue;
            path.push_back(candidates[i]);
            dfs(candidates,i,target,path,sum+candidates[i],res);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        dfs(candidates,0,target,vector<int>(),0,res);
        return res;
    }
};
// @lc code=end

