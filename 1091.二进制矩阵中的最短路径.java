/*
 * @lc app=leetcode.cn id=1091 lang=java
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start

import java.util.PriorityQueue;

class Solution {
    //Dfs方法超时
    /* 
    void Dfs(int [][] grid,boolean[][] visited,int i,int j,int step,int[][] dp){
        if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || visited[i][j] || grid[i][j]==1) return;
        // if(i==grid.length-1 && j==grid[0].length-1) dp[i][j]=step;
        visited[i][j]=true;
        dp[i][j]=Math.min(dp[i][j],step);
        Dfs(grid,visited,i+1,j,step+1,dp);
        Dfs(grid,visited,i-1,j,step+1,dp);
        Dfs(grid,visited,i,j+1,step+1,dp);
        Dfs(grid,visited,i,j-1,step+1,dp);
        Dfs(grid,visited,i+1,j+1,step+1,dp);
        Dfs(grid,visited,i+1,j-1,step+1,dp);
        Dfs(grid,visited,i-1,j+1,step+1,dp);
        Dfs(grid,visited,i-1,j-1,step+1,dp);
        visited[i][j]=false;
    }

    public int shortestPathBinaryMatrix(int[][] grid) {
        int gridlen=grid.length;
        boolean[][] visited=new boolean[gridlen][gridlen];
        int[][] dp=new int[gridlen][gridlen];
        for(int i=0;i<gridlen;i++){
            for(int j=0;j<gridlen;j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        Dfs(grid,visited,0,0,1,dp);
        return dp[gridlen-1][gridlen-1]<Integer.MAX_VALUE?dp[gridlen-1][gridlen-1]:-1;
    }
    */

    //Bfs方法
    static int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int [][] dp = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = 1;
        if(grid[0][0] == 1) return -1;
        PriorityQueue <int[]> pq = new PriorityQueue <>((a, b)->(dp[a[0]][a[1]]-dp[b[0]][b[1]]));
        pq.offer(new int[]{0, 0});
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            for(int[] dir : dirs){
                int x = cur[0] + dir[0];
                int y = cur[1] + dir[1];
                if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1 || dp[x][y] != Integer.MAX_VALUE) continue;
                dp[x][y] = dp[cur[0]][cur[1]] + 1;
                pq.offer(new int[]{x, y});
            }
        }
        return dp[n-1][n-1] == Integer.MAX_VALUE? -1 : dp[n-1][n-1];
    }
}
// @lc code=end

