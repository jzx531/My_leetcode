/*
 * @lc app=leetcode.cn id=433 lang=java
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
        if (!bankSet.contains(endGene)) return -1;
        if (startGene.equals(endGene)) return 0;

        char[] keys = {'A', 'C', 'G', 'T'};
        Queue<String> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();

        queue.offer(startGene);
        visited.add(startGene);

        int step = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String s = queue.poll();

                for (int pos = 0;pos < 8; pos++) {
                    for (char c : keys) {
                        if (s.charAt(pos) == c) continue;

                        StringBuilder sb = new StringBuilder(s);
                        sb.setCharAt(pos, c);
                        String newGene = sb.toString();

                        if (newGene.equals(endGene)) return step;

                        if (bankSet.contains(newGene) && !visited.contains(newGene)) {
                            queue.offer(newGene);
                            visited.add(newGene);
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
}

// @lc code=end

