/*
 * @lc app=leetcode.cn id=1047 lang=java
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
    // public String removeDuplicates(String s) {
    //     int n = s.length();
    //     String res = s;
    //     for(;;){
    //         for(int i = 0;i< res.length()-1;i++)
    //         {
    //             if(res.charAt(i) == res.charAt(i+1))
    //             {
    //                 if(i == 0) res = res.substring(i+2);
    //                 else res = res.substring(0,i) + res.substring(i+2);
    //                 break;
    //             }
    //         }
    //         if(n == res.length())
    //         {
    //             return res;
    //         }
    //         n = res.length();
    //     }
    // }

    public String removeDuplicates(String s) {
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()){
            int n = sb.length();
            if(n > 0 && sb.charAt(n - 1) == c){
                sb.deleteCharAt(n - 1);
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

}
// @lc code=end

