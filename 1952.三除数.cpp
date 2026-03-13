/*
 * @lc app=leetcode.cn id=1952 lang=cpp
 *
 * [1952] 三除数
 */

// @lc code=start
class Solution {
public:
    bool isThree(int n) {
        if(n <= 2) return false;
        int flag = 0;
        for (int i = 2; i <= n/2;i++)
        {
            if(!(n % i)){
                if(flag) return false;
                flag++;  
            }
        }
        if(!flag) return false;
        return true;
    }
};
// @lc code=end

