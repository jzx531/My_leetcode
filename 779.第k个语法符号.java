/*
 * @lc app=leetcode.cn id=779 lang=java
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution {
    public int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        if(k > 1<<(n-2)) return 1^kthGrammar(n-1, k-(1<<(n-2)));
        else return kthGrammar(n-1, k);
    }
}
// @lc code=end

