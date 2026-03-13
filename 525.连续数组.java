/*
 * @lc app=leetcode.cn id=525 lang=java
 *
 * [525] 连续数组
 */

// @lc code=start

import java.util.List;

class Solution {
    int maxLength;

    // public int findMaxLength(int[] nums) {
    //     int len = nums.length;
    //     for(int i = 0; i <len; i++){
    //         List<Integer> tempList = new ArrayList<>();
    //         permute(nums, i, nums.length, tempList, 0, 0);
    //     }
    //     return maxLength;
    // }

    // public void permute(int[] nums, int start, int end, List<Integer> tempList, int cnt0,int cnt1) 
    // {
    //     if(start == end) return;
    //     if(nums[start] == 0){
    //         cnt0++;
    //         tempList.add(nums[start]);
    //     }
    //     else{
    //         cnt1++;
    //         tempList.add(nums[start]);
    //     }
    //     if(cnt0 != 0 && cnt1!= 0 &&cnt0 == cnt1){
    //         maxLength = Math.max(maxLength, tempList.size());                
    //     }
    //     permute(nums, start+1, end, tempList, cnt0, cnt1);
    // }

    public int findMaxLength(int [] nums)
    {
        int len = nums.length;
        Map <Integer, Integer> map = new HashMap <>();
        int maxLength = 0;
        int count = 0;
        map.put(0,-1);
        for(int i = 0; i < len; i++)
        {
            int num = nums[i] == 0? -1 : 1;
            count += num;
            if(map.containsKey(count))
            {
                maxLength = Math.max(maxLength, i - map.get(count));
            }
            else
            {
                map.put(count,i);
            }
        }
        return maxLength;
    }
}
// @lc code=end

