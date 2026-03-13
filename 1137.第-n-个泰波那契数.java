/*
 * @lc app=leetcode.cn id=1137 lang=java
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
    static List<Integer> memo = new ArrayList<>();

    static {
        memo.add(0); // T0
        memo.add(1); // T1
        memo.add(1); // T2
    }

    public int tribonacci(int n) {
        if (n < memo.size()) {
            return memo.get(n);
        }
        int val = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        memo.add(val);
        return val;
    }
}

// @lc code=end

