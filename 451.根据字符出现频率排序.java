/*
 * @lc app=leetcode.cn id=451 lang=java
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
/* 
class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> map.get(b) - map.get(a));
        pq.addAll(map.keySet());
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {
            char c = pq.poll();
            int count = map.get(c);
            for (int i = 0; i < count; i++) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}*/

import java.util.Arrays;

class Solution {
    public String frequencySort(String s) {
        // 1. 统计频率
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // 2. 获取所有不重复的字符，并转为 Character[]
        Character[] uniqueChars = new Character[map.size()];
        int i = 0;
        for (char c : map.keySet()) {
            uniqueChars[i++] = c;
        }

        // 3. 按频率降序排序
        Arrays.sort(uniqueChars, (a, b) -> Integer.compare(map.get(b), map.get(a)));

        // 4. 构造结果：每个字符添加 map.get(c) 次
        StringBuilder sb = new StringBuilder();
        for (char c : uniqueChars) {
            for (int j = 0; j < map.get(c); j++) {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}
// @lc code=end

