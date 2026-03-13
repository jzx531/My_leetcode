/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        vector<int> bits(32, 0);
        int i = 0;
        while (n) {
            bits[i++] = n & 1;
            n >>= 1;
        }
        for (int j = 0; j < 32; j++) {
            res <<= 1;
            res |= bits[j];
        }
        return res;
    }
};
// @lc code=end

