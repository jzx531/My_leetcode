/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    bool isSelfDividing(int num) {
        if(num<10) return true;
        int n=num;
        while(n){
            int d=n%10;
            if(d==0 || num%d!=0) return false;
            n/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

