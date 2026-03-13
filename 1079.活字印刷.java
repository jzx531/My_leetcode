/*
 * @lc app=leetcode.cn id=1079 lang=java
 *
 * [1079] 活字印刷
 */

// @lc code=start

import java.util.List;

class Solution {
    void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void permute(char[] s, String cur, int start, Set<String> set) {
        if (start == s.length) return;

        for (int i = start; i < s.length; i++) {
            swap(s, start, i);
            String newStr = cur + s[start];
            set.add(newStr);  // 每次加一个前缀
            permute(s, newStr, start + 1, set);
            swap(s, start, i); // 回溯
        }
    }

    public int numTilePossibilities(String tiles) {
        Set<String> set = new HashSet<>();
        permute(tiles.toCharArray(), "", 0, set);
        return set.size();
    }
}
// @lc code=end

