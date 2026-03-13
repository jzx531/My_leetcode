/*
 * @lc app=leetcode.cn id=384 lang=java
 *
 * [384] 打乱数组
 */

// @lc code=start

import java.lang.reflect.Array;
import java.util.ArrayList;

class Solution {

    // private ArrayList<int[]> res = new ArrayList<>();
    // private int[] nums;
    // private int[] original;

    // public Solution(int[] nums) {
    //     permutation(nums,0);
    //     this.nums = nums.clone();
    //     this.original = nums.clone();
    // }
    
    // public int[] reset() {
    //     this.nums = original.clone();
    //     return nums;
    // }
    
    // public int[] shuffle() {
    //     int index = (int)(Math.random() * res.size());
    //     return res.get(index);
    // }

    // public void  permutation(int[] nums,int start) {
    //     int n = nums.length;
    //     for(int i=start;i<n;i++){
    //         for(int j = i;j<n;j++){
    //             if(i!=j){
    //                 swap(nums,i,j);
    //                 permutation(nums,i+1);
    //                 swap(nums,i,j);
    //             }
    //             res.add(nums.clone());
    //         }
    //     }
    // }
    // private void swap(int[] nums,int i,int j){
    //     int temp = nums[i];
    //     nums[i] = nums[j];
    //     nums[j] = temp;
    // }

    int[] nums;
    int[] original;

    public Solution(int[] nums) {
        this.nums = nums;
        this.original = new int[nums.length];
        System.arraycopy(nums, 0, original, 0, nums.length);
    }
    
    public int[] reset() {
        System.arraycopy(original, 0, nums, 0, nums.length);
        return nums;
    }
    
    public int[] shuffle() {
        Random random = new Random();
        for (int i = 0; i < nums.length; ++i) {
            int j = i + random.nextInt(nums.length - i);
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return nums;
    }


}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
// @lc code=end

