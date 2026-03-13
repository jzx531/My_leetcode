/*
 * @lc app=leetcode.cn id=457 lang=java
 *
 * [457] 环形数组是否存在循环
 */

// @lc code=start
class Solution {
    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        // System.out.println(n);
        for(int i=0;i<n;i++){
            nums[i] %= n;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==n) continue;
            if(nums[i]==-n) continue;
            if(nums[i]==0) continue;
            int start = i;
            int next = start;
            int steps = 0;
            boolean flag = nums[start] > 0;
            // System.out.printf("start=%d",start);
            while(true){
                if(flag && nums[next]<0) break;
                if(!flag && nums[next]>0) break;
                next = (next+nums[next]);
                if(next >= 0) next %= n;
                else next = n+next;
                // System.out.printf("next=%d",nums[next]);
                if(nums[next]==n) break;
                if(nums[next]==-n) break;
                if(nums[next]==0) break;

                // System.out.println(next);
                if(next==start) return true;

                if(++steps > n){
                    return true;
                }
            }
        }
        return false;
    }
}
// @lc code=end

