/*
 * @lc app=leetcode.cn id=503 lang=java
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
    // public int[] nextGreaterElements(int[] nums) {
    //     int n = nums.length;
    //     if(n == 1) return new int[]{-1};
    //     int[] res = new int[n];

    //     for(int i = 0; i < n; i++)
    //     {
    //         for(int j = (i+1)%n ;j != i; j = (j+1)%n)
    //         {
    //             if(nums[j] > nums[i])
    //             {
    //                 res[i] = nums[j];
    //                 break;
    //             }
    //             if((j+1)%n == i)
    //             {
    //                 res[i] = -1;
    //             }
    //         }
    //     }
    //     return res;
    // }

    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int [] res = new int[n];
        Arrays.fill(res,-1);
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < 2*n-1; i++)
        {
            while(!stack.isEmpty() && nums[stack.peek()] < nums[i%n])
            {
                res[stack.pop()] = nums[i%n];
            }
            stack.push(i%n);
        }
        return res;

    }

}
// @lc code=end

