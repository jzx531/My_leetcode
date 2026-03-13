/*
 * @lc app=leetcode.cn id=508 lang=java
 *
 * [508] 出现次数最多的子树元素和
 */

// @lc code=start

import java.util.Map;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<Integer,Integer> map = new HashMap<>();
    int maxCnt = 0;
    public int[]findFrequentTreeSum(TreeNode root) {
        dfs(root);
        List<Integer> list = new ArrayList<>();
        for(Map.Entry<Integer,Integer> entry : map.entrySet())
        {
            int cnt = entry.getValue();
            if(cnt == maxCnt)
            {
                list.add(entry.getKey());
            }
        }
        return list.stream().mapToInt(Integer::valueOf).toArray();
    }

    public int dfs(TreeNode node)
    {
        if(node == null){
            return 0;
        }
        int sum = node.val + dfs(node.left) + dfs(node.right);
        map.put(sum,map.getOrDefault(sum, 0)+1);
        maxCnt = Math.max(maxCnt,map.get(sum));
        return sum;
    }
}
// @lc code=end

