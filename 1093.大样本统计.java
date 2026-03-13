/*
 * @lc app=leetcode.cn id=1093 lang=java
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
    public double[] sampleStats(int[] count) {
        double[] res = new double[5];
        int n = count.length;

        // 最小值
        for (int i = 0; i < n; i++) {
            if (count[i] > 0) {
                res[0] = i;
                break;
            }
        }

        // 最大值
        for (int i = n - 1; i >= 0; i--) {
            if (count[i] > 0) {
                res[1] = i;
                break;
            }
        }

        long totalCount = 0;
        long totalSum = 0;
        int mode = 0, modeCount = 0;

        for (int i = 0; i < n; i++) {
            if (count[i] > 0) {
                totalCount += count[i];
                totalSum += (long) i * count[i];
                if (count[i] > modeCount) {
                    modeCount = count[i];
                    mode = i;
                }
            }
        }

        // 平均数
        res[2] = (double) totalSum / totalCount;

        // 中位数
        long half1 = (totalCount + 1) / 2;
        long half2 = (totalCount % 2 == 0) ? (totalCount / 2 + 1) : half1;
        int m1 = -1, m2 = -1;
        long cumsum = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > 0) {
                cumsum += count[i];
                if (m1 == -1 && cumsum >= half1) m1 = i;
                if (m2 == -1 && cumsum >= half2) {
                    m2 = i;
                    break;
                }
            }
        }
        res[3] = (m1 + m2) / 2.0;

        // 众数
        res[4] = mode;

        return res;
    }
}

/* 
class Solution {
    public double[] sampleStats(int[] count) {
        
        double[] res = new double[5];
        Arrays.sort(count);
        int n = count.length;
        res[0] = (double) count[0];
        res[1] = (double) count[n -1];
        Map<Integer, Integer> map = new HashMap<>();
        double sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += count[i];
            if(!map.containsKey(count[i]))
            {
                map.put(count[i], 1);
            }
            map.put(count[i], map.get(count[i]) + 1);
        }
        res[2] = sum/n;

        if(n % 2 == 0){
            res[3] = (double) (count[n/2] + count[n/2 - 1])/2;
        }
        else res[3] = (double) count[n/2];

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            pq.offer(new int[]{entry.getValue(), entry.getKey()});
        }
        res[4] = (double) pq.peek()[0];
        
        return res;
    }
}*/
// @lc code=end

