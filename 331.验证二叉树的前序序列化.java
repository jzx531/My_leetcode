/*
 * @lc app=leetcode.cn id=331 lang=java
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
    public boolean isValidSerialization(String preorder) {
        if(preorder.length() == 1 && preorder.charAt(0) == '#'){
            return true;
        }
        
        String[] nodes = preorder.split(",");
        int n = nodes.length;

        int numcount = 0;
        int sharpcount = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 && nodes[i].equals("#"))
            {
                return false;
            }

            if(Character.isDigit(nodes[i].charAt(0)))
            {
                numcount++;
            }

            if(nodes[i].equals("#"))
            {
                sharpcount++;
                if(sharpcount > numcount + 1)
                {
                    return false;
                }
            }

            if(sharpcount == numcount + 1 && i < n - 1)
            {
                return false;
            }

        }

        if(sharpcount!= numcount + 1)
        {
            return false;
        }
        return true;
    }
}
// @lc code=end

