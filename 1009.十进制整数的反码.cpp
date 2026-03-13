/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
int bitwiseComplement(int n) {
    if (n == 0) return 1; // 处理 n = 0 的情况
    int res = 0;
    int i = 0;
    while (n) {
        if (!(n & 1)) res|= (1 << i); // 若 n 的第 i 位为 0，则将 res 的第 i 位设置为 1
        n >>= 1;
        ++i;
    }
    return res;
}
};
// @lc code=end

