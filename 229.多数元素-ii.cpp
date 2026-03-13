/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<3){
            unordered_set<int> s;
            for(int i=0;i<nums.size();i++){
                s.insert(nums[i]);
            }
            return vector<int>(s.begin(),s.end());
        }
        
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            int count = 1;
            while(i < (n-1) && nums[i] == nums[i+1])
            {
                count++;
                i++;
            }
            if(count > (n/3))
                res.push_back(nums[i]);
        }
        return res;
    }
};
// @lc code=end

