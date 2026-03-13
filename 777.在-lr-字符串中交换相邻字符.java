/*
 * @lc app=leetcode.cn id=777 lang=java
 *
 * [777] 在 LR 字符串中交换相邻字符
 */

// @lc code=start
class Solution {
    public boolean canTransform(String start, String result) {
        int n = start.length();
        int m = result.length();
        if (n!= m) {
            return false;
        }
        int i=0,j=0;
        while(i<n && j <n)
        {
            while(i<n && start.charAt(i) == 'X') i++;
            while(j<n && result.charAt(j) == 'X') j++;
            if (i==n && j==n) {
                return true;
            }
            if (i==n || j==n) {
                return false;
            }
            if (start.charAt(i) != result.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i<j) {
                return false;
            }
            if (start.charAt(i) == 'R' && i>j) {
                return false;
            }
            i++;
            j++;
        }
        while(i<n){
            if(start.charAt(i)!='X')
                return false;
            i++;
        }
        while(j<n){
            if(result.charAt(j)!='X')
                return false;
            j++;
        }
        return true;
    }
}
// @lc code=end

