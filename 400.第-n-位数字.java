/*
 * @lc app=leetcode.cn id=400 lang=java
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
    public int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        int Nth = findNthDigit(n, 1);
        long remain = n;
        long base = 0;

        for (int i = 1; i < Nth; i++) {
            base += i * 9 * (long) Math.pow(10, i - 1);
        }
        remain -= base;

        int pos = (int )remain% Nth;
        long num = remain / Nth;
 
        base = 0;
        for (int i = 1; i < Nth; i++) {
            base += 9 * (int) Math.pow(10, i - 1);
        }
        num += base;
        num = pos == 0 ? num : num + 1;
        pos = pos == 0? Nth - 1 : pos - 1;
        return Long.toString(num).charAt(pos)-'0';
    }

    public int findNthDigit(long n,int i) {
        if (n > 0) {
            return findNthDigit(n - i * 9 * (long) Math.pow(10, i - 1), i + 1) + 1;
        }else{
            return 0;
        }
    }
}
// @lc code=end

