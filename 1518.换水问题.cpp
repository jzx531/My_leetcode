/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换水问题
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange) return numBottles;
        int res = numBottles;
        while(numBottles >= numExchange){
            int temp = numBottles / numExchange;
            res += temp;
            numBottles = temp + numBottles % numExchange;
        }
        return res;
    }
};
// @lc code=end

