/*
 * @lc app=leetcode.cn id=421 lang=java
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
    /* 
    public int findMaximumXOR(int[] nums) {
        int len = nums.length;
        int res = 0;
        for (int i = 0; i <len; ++i) {
            for(int j = i+1; j < len; ++j)
            {
                res = Math.max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }*/

    //使用字典树
    class Trie {
        // 左子树指向表示 0 的子节点
        Trie left = null;
        // 右子树指向表示 1 的子节点
        Trie right = null;
    }

    Trie root = new Trie();
    static final int BIT_SIZE = 30;

    void add(int num) {
        Trie cur = root;
        for(int i = BIT_SIZE; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if(bit == 0)
            {
                if(cur.left == null)
                    cur.left = new Trie();
                cur = cur.left;
            }
            else
            {
                if(cur.right == null)
                    cur.right = new Trie();
                cur = cur.right;
            }
        }
    }

    int check(int num) {
        Trie cur = root;
        int res = 0;
        for(int i = BIT_SIZE ; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if(bit == 0)
            {
                // 如果当前位为 0，则下一位可以为 0 或 1，选择 1 则异或结果为 0，选择 0 则异或结果为 1
                if(cur.right!= null)
                {
                    res = (res << 1) | 1;
                    cur = cur.right;
                }
                else
                {
                    res = (res << 1) | 0;
                    cur = cur.left;
                }
            }
            else
            {
                if(cur.left != null)
                {
                    res = (res << 1) | 1;
                    cur = cur.left;
                }
                else
                {
                    res = (res << 1) | 0;
                    cur = cur.right;
                }
            }
        }
        return res;
    }

    public int findMaximumXOR(int[] nums) {
        int res = 0;
        for(int num : nums)
        {
            add(num);
            res = Math.max(res, check(num));
        }
        return res;
    }    
}
// @lc code=end

