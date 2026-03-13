/*
 * @lc app=leetcode.cn id=242 lang=java
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
    public String sort(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
    public boolean isAnagram(String s, String t) {
        String s1 = sort(s);
        String t1 = sort(t);
        return s1.equals(t1);
    }
}
// @lc code=end

