/*
 * @lc app=leetcode.cn id=538 lang=java
 *
 * [538] 把二叉搜索树转换为累加树
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
    int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root != null) {
            convertBST(root.right);
            sum += root.val;
            root.val = sum;
            convertBST(root.left);
        }
        return root;
    }
}

// class Solution {
//     private int sum = 0;
//     public TreeNode convertBST(TreeNode root) {
//         TreeNode res = null;
//         ArrayList<Integer> list = new ArrayList<Integer>();
//         inorder(root, list);
//         res = buildTree(list, 0, list.size() - 1);
//         return res;
//     }

//     public void inorder(TreeNode root, ArrayList<Integer> list) {
//         if(root == null) return;
//         inorder(root.right, list);
//         sum += root.val;
//         list.add(sum);
//         inorder(root.left, list);
//     }

//     public TreeNode buildTree(ArrayList<Integer> list, int start, int end) {
//         if(start > end) return null;
//         int mid = (start + end) / 2;
//         TreeNode root = new TreeNode(list.get(mid));
//         root.right = buildTree(list, start, mid - 1);
//         root.left = buildTree(list, mid + 1, end);
//         return root;
//     }
// }

// @lc code=end

