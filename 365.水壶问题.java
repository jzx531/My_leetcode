/*
 * @lc app=leetcode.cn id=365 lang=java
 *
 * [365] 水壶问题
 */

// @lc code=start

import java.util.HashMap;

class Solution {
    public Integer hash(int x, int y) {
        return x * 1000 + y;
    }
    HashMap<Integer, Boolean> visitedMap = new HashMap<>();
    //一共有如下操作:
    //1. 把x水壶倒满
    //2. 把y水壶倒满
    //3. 把x水壶灌进y水壶
    //4. 把y水壶灌进x水壶
    //5. 把x水壶倒空
    //6. 把y水壶倒空
    public boolean canMeasureWater(int x, int y, int target) {
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{0, 0});
        // visitedMap.put(hash(0, 0), true);
        while (!stack.isEmpty()) {
            int[] cur = stack.pop();
            int xCur = cur[0];
            int yCur = cur[1];
            if(visitedMap.containsKey(hash(xCur,yCur)))
            {
                continue;
            }
            visitedMap.put(hash(xCur,yCur),true);
            if (xCur == target || yCur == target || xCur + yCur == target) {
                return true;
            }
            //1. 把x水壶倒满
            stack.push(new int[]{x, yCur});
            //2. 把y水壶倒满
            stack.push(new int[]{xCur, y});
            //3. 把x水壶灌进y水壶
            stack.push(new int[]{xCur-Math.min(xCur,y-yCur), yCur + Math.min(xCur,y-yCur)});
            //4. 把y水壶灌进x水壶
            stack.push(new int[]{xCur + Math.min(yCur, x - xCur), yCur - Math.min(yCur, x - xCur) });
            //5. 把x水壶倒空
            stack.push(new int[]{0, yCur});
            //6. 把y水壶倒空
            stack.push(new int[]{xCur, 0});
            
        }
        return false;
    }
}
// @lc code=end

