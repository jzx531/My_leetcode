/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    void backtrace(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& res) {
        int nt = temp.size();
        if(nt >= 2){
            res.push_back(temp);
        }
        
        unordered_set<int> s;
        for(int i = start; i < nums.size(); i++){
            if(s.count(nums[i])){ continue;}
            s.insert(nums[i]);
            if(temp.empty() || nums[i] >= temp.back()){
                temp.push_back(nums[i]);
                backtrace(nums, i+1, temp, res);
                temp.pop_back();
            }   
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrace(nums, 0, temp, res);
        return res;
    }
};
// @lc code=end

