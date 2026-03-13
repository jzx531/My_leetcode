/*
 * @lc app=leetcode.cn id=542 lang=java
 *
 * [542] 01 矩阵
 */

// @lc code=start

import java.util.Deque;

class Solution {
    static int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        Deque<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    queue.offer(new int[]{i,j});
                    visited[i][j] = true;
                }
            }
        }
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];
            for(int[] dir:dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){
                    mat[nx][ny] = mat[x][y] + 1;
                    queue.offer(new int[]{nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return mat;

    }

}
// @lc code=end

