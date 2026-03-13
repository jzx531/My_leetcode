/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    void backtrace(vector<int> &nums,vector<int> &path,vector<vector<int>> &res,int start)
    {
        res.push_back(path);
        int n = nums.size();
        for(int i = start;i<n;++i)
        {
            path.push_back(nums[i]);
            backtrace(nums,path,res,i+1);
            path.pop_back();
            int j = 1;
            while(i+j<n && nums[i+j]==nums[i])
            {
                j++;
            }
            i += j-1;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(),nums.end());
        backtrace(nums,path,res,0);
        return res;
    }
};
// @lc code=end

