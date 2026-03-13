/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrace(nums,path,res,0);
        return res;
    }
};
// @lc code=end

