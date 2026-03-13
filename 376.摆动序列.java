/*
 * @lc app=leetcode.cn id=376 lang=java
 *
 * [376] 摆动序列
 */

// @lc code=start

import java.util.ArrayList;

class Solution {
    // void backtrace(int[]nums,int start,int end,ArrayList<Integer> path,boolean flag,Integer []res)
    // {
    //     if(start>end)
    //     {
    //         res[0] = Math.max(res[0],path.size());
    //         // System.out.println(res);
    //         return;
    //     }
    //     for(int i=start;i<=end;i++)
    //     {
    //         if(path.size()==0)
    //         {
    //             path.add(nums[i]);
    //             backtrace(nums, i+1, end, path, flag, res);
    //             path.remove(path.size()-1);
    //         }
    //         else if(flag==true)
    //         {
    //             if(nums[i]>path.get(path.size()-1))
    //             {
    //                 path.add(nums[i]);
    //                 backtrace(nums, i+1, end, path, !flag, res);
    //                 path.remove(path.size()-1);
    //             }
    //         }
    //         else if(flag==false)
    //         {
    //             if(nums[i]<path.get(path.size()-1))
    //             {
    //                 path.add(nums[i]);
    //                 backtrace(nums, i+1, end, path, !flag, res);
    //                 path.remove(path.size()-1);
    //             }
    //         }     
    //     } 
    // }
    // public int wiggleMaxLength(int[] nums) {
    //     Integer [] res = new Integer[1];
    //     res[0] = 1;
    //     ArrayList<Integer> path = new ArrayList<Integer>();
    //     backtrace(nums, 0, nums.length-1, path, true, res);
    //     path.clear();
    //     backtrace(nums, 0, nums.length-1, path, false, res);
    //     return res[0];
    // }

    public int wiggleMaxLength(int[] nums) {
    int down = 1, up = 1;
    for (int i = 1; i < nums.length; i++) {
        if (nums[i] > nums[i - 1])
            up = down + 1;
        else if (nums[i] < nums[i - 1])
            down = up + 1;
    }
    return nums.length == 0 ? 0 : Math.max(down, up);
}


}
// @lc code=end

