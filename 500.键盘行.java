/*
 * @lc app=leetcode.cn id=500 lang=java
 *
 * [500] 键盘行
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public String[] findWords(String[] words) {
        // 创建映射：字符 -> 行号 (统一转为小写处理)
        Map<Character, Integer> rowMap = new HashMap<>();
        String row1 = "qwertyuiop";
        String row2 = "asdfghjkl";
        String row3 = "zxcvbnm";

        for (char c : row1.toCharArray()) rowMap.put(c, 1);
        for (char c : row2.toCharArray()) rowMap.put(c, 2);
        for (char c : row3.toCharArray()) rowMap.put(c, 3);

        List<String> resultList = new ArrayList<>();

        for (String word : words) {
            if (word == null || word.isEmpty()) {
                // 根据题目约束，通常不会有空字符串，但做个防御性编程
                continue; 
            }
            
            // 获取第一个字符所在的行 (转为小写)
            int row = rowMap.get(Character.toLowerCase(word.charAt(0)));
            boolean sameRow = true;

            // 检查剩余字符是否在同一行
            for (int i = 1; i < word.length(); i++) {
                if (rowMap.get(Character.toLowerCase(word.charAt(i))) != row) {
                    sameRow = false;
                    break;
                }
            }

            if (sameRow) {
                resultList.add(word);
            }
        }

        // 将 List 转换为数组返回
        return resultList.toArray(new String[0]);
    }
}
// @lc code=end

