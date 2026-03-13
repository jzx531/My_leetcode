/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    void changedir(int &i, int &j, int &dir)
    {
        switch(dir){
            case 0: j++; break;
            case 1: i++; break;
            case 2: j--; break;
            case 3: i--; break;
        };
    }
    void redir(int &i, int &j, int &dir)
    {
        switch(dir){
            case 0: j--; break;
            case 1: i--; break;
            case 2: j++; break;
            case 3: i++; break;
        };
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0,dir = 0;
        while(res.size() < m*n)
        {
            if(visited[i][j])
            {
                redir(i,j,dir);
                dir = (dir+1)%4;
                changedir(i,j,dir);
                continue;
            }

            res.push_back(matrix[i][j]);
            visited[i][j] = 1;

            if(dir ==0 && j == n-1)
            {
                dir = (dir+1)%4;
                changedir(i,j,dir);
            }
            else if(dir == 1 && i == m-1)
            {
                dir = (dir+1)%4;
                changedir(i,j,dir);
            }
            else if(dir == 2 && j == 0)
            {
                dir = (dir+1)%4;
                changedir(i,j,dir);
            }
            else if(dir == 3 && i == 0)
            {
                dir = (dir+1)%4;
                changedir(i,j,dir);
            }
            else{
                changedir(i,j,dir);
            }
        }
        return res;
    }
};
// @lc code=end

