/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for(int n : nums){
            auto ret =s.insert(n);
            if(!ret.second){
                res.push_back(n);
                break;
            }
        }
        int n = nums.size();
        long long sum = (n*(n+1))/2;
        long sumnums = accumulate(nums.begin(),nums.end(),0);
        res.push_back(sum-sumnums+res[0]);
        return res;
    }
};
// @lc code=end

