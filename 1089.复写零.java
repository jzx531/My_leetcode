/*
 * @lc app=leetcode.cn id=1089 lang=java
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
    public void duplicateZeros(int[] arr) {
        int n = arr.length;
        int [] res = new int[n];
        int j = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                res[j++] = 0;
                if(j == n){
                    break;
                }
                res[j++] = 0;   
            }
            else{
                res[j++] = arr[i];
            }
            if(j == n){
                break;
            }
        }
        for(int i = 0; i < n; i++){
            arr[i] = res[i];
        }
    }
}
// @lc code=end

