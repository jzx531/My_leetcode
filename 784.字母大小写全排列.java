/*
 * @lc app=leetcode.cn id=784 lang=java
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> res = new ArrayList<>();
        if (s == null || s.length() == 0) {
            return res;
        }
        char[] chars = s.toCharArray();
        backtrack(chars, 0, res);
        return res;
    
    }
    void backtrack(char[] chars, int index, List<String> res) {
        if (index == chars.length) {
            res.add(new String(chars));
            return;
        }
        if (Character.isLetter(chars[index])) {
            chars[index] = Character.toLowerCase(chars[index]);
            backtrack(chars, index + 1, res);
            chars[index] = Character.toUpperCase(chars[index]);
            backtrack(chars, index + 1, res);
        } else {
            backtrack(chars, index + 1, res);
        }
    }
}
// @lc code=end

