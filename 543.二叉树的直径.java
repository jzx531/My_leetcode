/*
 * @lc app=leetcode.cn id=543 lang=java
 *
 * [543] 二叉树的直径
 */

// @lc code=start
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
    int longest = 0;
    public int findDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if(root.left == null && root.right == null)
        {
            return 1;
        }
        int leftDepth = findDepth(root.left);
        int rightDepth = findDepth(root.right);
        return Math.max(leftDepth, rightDepth) + 1;
    }
    public int findPathLength(TreeNode root) {
        return findDepth(root.left)+findDepth(root.right);
    }
    public void findLongestPath(TreeNode root) {
        if (root == null) {
            return;
        }
        findLongestPath(root.left);
        findLongestPath(root.right);
        int pathLength = findPathLength(root);
        longest = Math.max(longest, pathLength);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null)
        {
            return 0;
        }
        findLongestPath(root);
        return longest;
    }
}
// @lc code=end

