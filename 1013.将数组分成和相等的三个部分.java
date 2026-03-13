/*
 * @lc app=leetcode.cn id=1013 lang=java
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = 0;
        for (int num : arr) {
            total += num;
        }
        if (total % 3 != 0) {
            return false;
        }
        int target = total / 3;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum == target) {
                count++;
                sum = 0;
                if (count == 2 && i != arr.length - 1) {
                    return true;
                }
            }
        }
        return false;
    }
}
// @lc code=end

