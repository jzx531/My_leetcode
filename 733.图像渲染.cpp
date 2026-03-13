/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        stack<pair<int, int>> center;
        center.push(make_pair(sr, sc));
        int m = image.size();
        int n = image[0].size();
        int old_color = image[sr][sc];
        image[sr][sc] = color;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        while(!center.empty())
        {
            int x = center.top().first;
            int y = center.top().second;
            center.pop();
            if(x-1>=0)
            {
                if(!visited[x-1][y]){
                    visited[x-1][y] = 1;
                    if(image[x-1][y] == old_color)
                    {
                        image[x-1][y] = color;
                        center.push(make_pair(x-1, y));
                    }
                }
            }
            if(y-1>=0)
            {
                if(!visited[x][y-1]){
                    visited[x][y-1] = 1;
                    if(image[x][y-1] == old_color)
                    {
                        image[x][y-1] = color;
                        center.push(make_pair(x, y-1));
                    }
                }
            }
            if(x+1<m ){
                if(!visited[x+1][y]){
                    visited[x+1][y] = 1;
                    if(image[x+1][y] == old_color)
                    {
                        image[x+1][y] = color;
                        center.push(make_pair(x+1, y));
                    }
                }
            }
            if(y+1<n)
            {
                if(!visited[x][y+1]){ 
                    visited[x][y+1] = 1;
                    if(image[x][y+1] == old_color)
                    {
                        image[x][y+1] = color;
                        center.push(make_pair(x, y+1));
                    }
                }
            }
        }
        return image;
    }
};
// @lc code=end

