/*
 * @lc app=leetcode.cn id=438 lang=java
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
import java.util.*;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int ls = s.length();
        int lp = p.length();
        if (ls < lp) return res;

        // 使用数组代替 HashMap
        int[] countp = new int[26]; // p 的字符计数
        for (int i = 0; i < lp; i++) {
            countp[p.charAt(i) - 'a']++;
        }

        int[] count = new int[26]; // 滑动窗口计数
        int lindex = 0;
        int rindex = 0;
        int i;

        Loop: while (lindex <= ls - lp) {

            // 找到第一个在 p 中出现的字符
            while (lindex <= ls - lp && countp[s.charAt(lindex) - 'a'] == 0) {
                lindex++;
            }

            if (lindex > ls - lp) break;

            if (rindex < lindex) rindex = lindex;
            // System.out.println("lindex: " + lindex + " rindex: " + rindex);
            for (i = rindex; i < lindex + lp; i++) {
                int idx = s.charAt(i) - 'a';
                if (countp[idx] == 0) { // 不在 p 中
                    Arrays.fill(count, 0); // 清空窗口计数
                    lindex = i + 1;
                    rindex = i + 1;
                    if (lindex > ls - lp) return res;
                    System.out.println("continue: " + lindex + " " + rindex);
                    continue Loop;
                    // break;
                }else{
                    count[idx]++;
                }
            }
            rindex = lindex + lp;
            // for(i = 0; i < 26; i++)
            // {
            //     if(count[i] > 0){
            //         System.out.printf("%c:%d ", (char)('a'+i), count[i]);
            //     }
            // }
            // System.out.println();

            // 比较两个数组是否相等
            if(Arrays.equals(count, countp))
            {
                res.add(lindex);
            }
            // System.out.println(lindex);
        
            // 窗口左侧字符出窗口，减 1
            int leftIdx = s.charAt(lindex) - 'a';
            if (count[leftIdx] > 0) count[leftIdx]--;
            lindex++;
            
        }
        return res;
    }
}
// @lc code=end

