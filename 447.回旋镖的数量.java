/*
 * @lc app=leetcode.cn id=447 lang=java
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int n = points.length;
        int res = 0;
        if(n < 3) return 0;
        for(int i=0;i<n;i++)
        {
            Map<Integer, Integer> map = new HashMap<>();
            for(int j=0;j<n;j++)
            {
                if(i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dis = dx * dx + dy * dy;
                map.put(dis, map.getOrDefault(dis, 0) + 1);
            }
            int count = 0;
            for(int value : map.values())
            {
                count += value * (value - 1);
            }
            // count /= 2;
            res += count;
            // System.out.println(count);
        }
        return res;
    }
}
// @lc code=end

