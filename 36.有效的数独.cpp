/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> box(9,vector<int>(9,0));

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')//若是'.' ，则直接跳过
                    continue;
                int val=board[i][j]-'1';//找出对应的值
                int box_index=i/3*3+j/3;//找出当前值所在的方框
                if(row[i][val]||col[j][val]||box[box_index][val])//若是之前出现过，则直接返回false
                    return false;
                else{//否则，进行统计
                    row[i][val]=1;
                    col[j][val]=1;
                    box[box_index][val]=1;
                }
            }
        }

        return true;
    }
};
// @lc code=end

