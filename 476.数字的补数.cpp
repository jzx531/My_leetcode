/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int i = 0;
        while(1) {
            if(!( num & 1)) {
                res |= (1<<i);
                // cout<<res<<endl;
            }
            num >>= 1;
            i++;
            // cout<<num<<endl;
            if(num == 0) {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

