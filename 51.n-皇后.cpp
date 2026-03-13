/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    bool isValid(int n,int x,int y,vector<string> &board)
    {
        for(int i = 0;i<n;++i)
        {
            if(board[i][y] == 'Q') return false;
        }
        for(int i = 0;i<n;++i){
            if(board[x][i] == 'Q') return false;
        }
        int i  = x;
        int j = y;
        while(i>=0 && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = x;
        j = y;
        while(i<n && j<n)
        {
            if(board[i][j] == 'Q') return false;
            i++;
            j++;
        }
        i=x;
        j=y;
        while(i>=0 && j<n)
        {
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        i=x;
        j=y;
        while(i<n && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        return true;
    }
        
    void backtrace(int n,vector<int>&y,int remain,vector<string>&path,vector<vector<string>>&res)
    {
        if(remain == 0)
        {
            res.push_back(path);
            return;
        }
        int i = remain - 1;
        for(int j = 0;j<n;++j)
        {
            if(y[j]) continue;
            if(isValid(n,i,j,path))
            {
                path[i][j] = 'Q';
                y[j]=1;
                backtrace(n,y,remain-1,path,res);
                y[j]=0;
                path[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> y(n,0);
        backtrace(n,y,n,board,res);
        return res;
    }
};
// @lc code=end

