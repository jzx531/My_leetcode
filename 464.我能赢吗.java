// /*
//  * @lc app=leetcode.cn id=464 lang=java
//  *
//  * [464] 我能赢吗
//  */

// // @lc code=start
// class Solution {
//     public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
//         if(desiredTotal< maxChoosableInteger) return true;
//         if((maxChoosableInteger*(maxChoosableInteger+1)/2)<desiredTotal) return false;

//         int[] nums = new int[maxChoosableInteger];
//         for (int i = 0; i < maxChoosableInteger; i++) {
//             nums[i] = i + 1;
//         }
//         return dfsFirst(nums,desiredTotal,0,new boolean[maxChoosableInteger]);
//         // return dfs(nums,desiredTotal,0,new boolean[maxChoosableInteger],true);
//     }

//     public boolean dfs(int[]nums,int target,int sum,boolean[] used,boolean first)
//     {
//         for(int i=0;i<nums.length;i++){
//             if(!used[i]){
//                 used[i]=true;
//                 if(sum+nums[i]>=target) return true;
//                 if(first){
//                     if(!dfs(nums,target,sum+nums[i],used,!first)){
//                         return true;
//                     }
//                 }
//                 else{
//                     if(dfs(nums,target,sum+nums[i],used,!first)){
//                         return true;
//                     }
//                 }

//                 used[i]=false;
//             }
//         }
//         return false;
//     }

//     public boolean dfsFirst(int[]nums,int target,int sum,boolean[] used){
        
//         for(int i=0;i<nums.length;i++){
//             if(!used[i]){
//                 used[i]=true;
//                 if((sum+nums[i])>=target) return true;
//                 if(!dfsSecond(nums,target,sum+nums[i],used)){
//                     return true;
//                 }
//                 used[i]=false;
//             }
//         }
//         return false;
//     }

    
//     public boolean dfsSecond(int[]nums,int target,int sum,boolean[] used){
        
//         for(int i=0;i<nums.length;i++){
//             if(!used[i]){
//                 used[i]=true;
//                 if((sum+nums[i])>=target) return true;
//                 if(!dfsFirst(nums,target,sum+nums[i],used)){
//                     return true;
//                 }
//                 used[i]=false;
//             }
//         }
//         return false;
//     }    
// }
class Solution {
    int n, t;
    int[] f = new int[1 << 20];
    // 1 true / -1 false
    int dfs(int state, int tot) {
        if (f[state] != 0) return f[state];
        for (int i = 0; i < n; i++) {
            if (((state >> i) & 1) == 1) continue;
            if (tot + i + 1 >= t) return f[state] = 1;
            if (dfs(state | (1 << i), tot + i + 1) == -1) return f[state] = 1;
        }
        return f[state] = -1;
    }
    public boolean canIWin(int _n, int _t) {
        n = _n; t = _t;
        if (n * (n + 1) / 2 < t) return false;
        if (t == 0) return true;
        return dfs(0, 0) == 1;
    }
}

// class Solution {
//     public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
//     if (desiredTotal <= 0) return true; // 特殊情况：目标为0时先手直接赢
//     if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;

//     // 初始化可选数字（1到maxChoosableInteger）
//     int[] nums = new int[maxChoosableInteger];
//     for (int i = 0; i < maxChoosableInteger; i++) {
//         nums[i] = i + 1;
//     }

//     // 使用备忘录缓存状态（用used数组的字符串表示作为key）
//     Map<String, Boolean> memo = new HashMap<>();
//     return canWin(nums, desiredTotal, 0, new boolean[maxChoosableInteger], memo, true);
// }

// private boolean canWin(int[] nums, int target, int sum, boolean[] used, 
//                       Map<String, Boolean> memo, boolean isFirstPlayer) {
//     // 检查备忘录
//     String key = Arrays.toString(used);
//     if (memo.containsKey(key)) {
//         return memo.get(key);
//     }

//     // 遍历所有可选数字
//     for (int i = 0; i < nums.length; i++) {
//         if (!used[i]) {
//             used[i] = true;
//             int newSum = sum + nums[i];

//             // 当前玩家是否能赢？
//             if (newSum >= target) { // 当前玩家达到目标，直接获胜
//                 used[i] = false; // 回溯
//                 memo.put(key, isFirstPlayer);
//                 return isFirstPlayer;
//             }

//             // 递归检查对手是否能赢
//             boolean opponentCanWin = canWin(nums, target, newSum, used, memo, !isFirstPlayer);
//             used[i] = false; // 回溯

//             // 如果对手不能赢，则当前玩家可以赢
//             if (!opponentCanWin) {
//                 memo.put(key, true);
//                 return true;
//             }
//         }
//     }

//     // 所有选择都尝试过，当前玩家无法获胜
//     memo.put(key, false);
//     return false;
// }
// }

// // @lc code=end

