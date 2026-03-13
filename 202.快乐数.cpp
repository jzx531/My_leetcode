/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    unordered_set<int> s;
    bool isHappy(int n) {
        if (n == 1) return true;
        if(n == 2) return false;
        if(s.count(n)) return false;
        s.insert(n);
        int dev;
        vector<int> nums;
        while(n>0){
            dev = n%10;
            n = n/10;
            nums.push_back(dev);
        }
        int sum = 0;
        {
            for(int i=0;i<nums.size();i++){
                sum += nums[i]*nums[i];
            }
        }
        return isHappy(sum);
    }
};
// @lc code=end

