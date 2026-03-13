/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.size() - 1, ib = b.size() - 1, carry = 0;
        string res;
        while (ia >= 0 || ib >= 0 || carry) {
            int sum = carry;
            if (ia >= 0) sum += a[ia--] - '0';
            if (ib >= 0) sum += b[ib--] - '0';
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

