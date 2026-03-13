/*
 * @lc app=leetcode.cn id=385 lang=java
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    int index = 0;
    public NestedInteger deserialize(String s) {
        if (s.charAt(index) == '[') { 
            index++; // 跳过左括号
            NestedInteger ni = new NestedInteger();
            while (s.charAt(index) != ']') { // 遇到右括号结束
                ni.add(deserialize(s)); // 递归处理子串
                if (s.charAt(index) == ',') { // 如果有逗号，跳过
                    index++;
                }
            }
            index++; // 跳过右括号
            return ni;
        }

        boolean isNegative = false;

        if(s.charAt(index) == '-')
        {
            isNegative = true;
            index++;
        }
        
        
        int num = 0;
        while (index < s.length() && s.charAt(index) >= '0' && s.charAt(index) <= '9') {
            num = num * 10 + (s.charAt(index) - '0');
            index++;
        }
        return new NestedInteger(isNegative ? -num : num);              
    }
}
// @lc code=end

