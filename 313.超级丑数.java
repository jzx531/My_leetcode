/*
 * @lc app=leetcode.cn id=313 lang=java
 *
 * [313] 超级丑数
 */

// @lc code=start

import java.util.Arrays;
import java.util.Map;

class Solution {
    //以下算法超时
    // public int nthSuperUglyNumber(int n, int[] primes) {
    //     Arrays.sort(primes);
    //     if(n == 1) return 1;
    //     int[] dp = new int[n];
    //     dp[0] = 1;
    //     dp[1] = primes[0];
    //     int pidx = 1;
    //     Map<Integer, Integer> map = new HashMap<>();
    //     map.put(dp[1],1);
    //     for(int i = 2; i < n; i++)
    //     {
    //         if(pidx >(primes.length-1)){
    //             dp[i] = Integer.MAX_VALUE;
    //             for(Map.Entry<Integer, Integer> entry:map.entrySet())
    //             {
    //                 dp[i] = Math.min(dp[i],entry.getKey()*dp[entry.getValue()]);
    //             }
    //             for(Map.Entry<Integer, Integer>  entry:map.entrySet()){
    //                 if(dp[i] == entry.getKey()*dp[entry.getValue()]){
    //                     map.put(entry.getKey(), map.get(entry.getKey()) + 1);
    //                 }
    //             }
    //             map.put(dp[i],1);
    //         }
    //         else{
    //             dp[i] = primes[pidx];
    //             for(Map.Entry<Integer, Integer> entry:map.entrySet())
    //             {
    //                 dp[i] = Math.min(dp[i],entry.getKey()*dp[entry.getValue()]);
    //             }
    //             map.put(dp[i],1);
                
    //             for(Map.Entry<Integer, Integer>  entry:map.entrySet()){
    //                 if(dp[i] == entry.getKey()*dp[entry.getValue()]){
    //                     map.put(entry.getKey(), map.get(entry.getKey()) + 1);
    //                 }
    //             }
    //             if(dp[i] == primes[pidx]){
    //                 pidx++;
    //             }
    //         }
    //     }
    //     return dp[n-1];
    // }

    public int nthSuperUglyNumber(int n, int[] primes) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        q.add(1);
        while (n-- > 0) {
            int x = q.poll();
            if (n == 0) return x;
            for (int k : primes) {
                if (k <= Integer.MAX_VALUE / x) q.add(k * x);
                if (x % k == 0) break;
            }
        }
        return -1; // never
    }


}
// @lc code=end

