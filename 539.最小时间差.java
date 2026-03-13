/*
 * @lc app=leetcode.cn id=539 lang=java
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        if (n > 1440) return 0;
        Collections.sort(timePoints);
        // timePoints.sort(this::compare);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            int diff = Math.abs(toMinutes(timePoints.get(i)) - toMinutes(timePoints.get(i - 1)));
            minDiff = Math.min(minDiff, diff);
        }
        int lastDiff = Math.abs(toMinutes(timePoints.get(0)) + 1440 - toMinutes(timePoints.get(n - 1)));
        minDiff = Math.min(minDiff, lastDiff);
        return minDiff;
    }

    private int toMinutes(String t) {
         int h1 = Integer.parseInt(t.substring(0, 2));
         int m1 = Integer.parseInt(t.substring(3));
        return h1 * 60 + m1;
    }
    

    private int compare(String t1, String t2) {
        int h1 = Integer.parseInt(t1.substring(0, 2));
        int m1 = Integer.parseInt(t1.substring(3));
        int h2 = Integer.parseInt(t2.substring(0, 2));
        int m2 = Integer.parseInt(t2.substring(3));
        if (h1 == h2) {
            return m1 - m2 < 0? -1 : 1;
        } else {
            return h1 - h2 < 0? -1 : 1;
        }
    }
}
// @lc code=end

