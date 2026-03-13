/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int res =0;
    //     for (int i = 1; i < prices.size(); i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (prices[i] > prices[j])
    //             {
    //                 res = max(res, prices[i] - prices[j]);
    //             }
    //         }
    //     }
    //     return res;
    // }
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = prices[0];
        for(int i = 1; i < prices.size() ; i++)
        {
            if(prices[i] < min_price)
            {
                min_price = prices[i];
            }
            else
            {
                res = max(res, prices[i] - min_price);
            }
        }
        return res;
    }
};
// @lc code=end

